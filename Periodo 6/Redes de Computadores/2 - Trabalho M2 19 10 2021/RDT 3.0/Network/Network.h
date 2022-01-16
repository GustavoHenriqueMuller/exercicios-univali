#ifndef RDT_TRANSPORT_H
#define RDT_TRANSPORT_H

#include "Clock.h"
#include "Log.h"
#include "Binary.h"
#include <cmath>

/**
 * Estrutura básica para um pacote
 */
struct Packet {
    int seqNum;
    bool ack;
    std::string checkSum;
    std::string *payload;
};

const int PAYLOAD_SIZE = 5;
const int DELAY = 2;
int ACTUAL_SEQNUM = 0;
Packet* sharedPacket = nullptr;
std::string receivedMessage;

namespace Network {

    Packet* createPacket(int seqNum, bool ack, std::string checkSum, std::string message) {
        Packet* packet = new Packet;
        packet->seqNum = seqNum;
        packet->ack = ack;
        packet->checkSum = checkSum;
        packet->payload = new string(message);
        return packet;
    }

    string generateCheckSum(std::string message) {
        std::string sum = decimalToBinary(int(message.at(0)));
        for(int i = 1; i < message.length(); i++)
            sum = binaryAddition(sum, decimalToBinary(int(message.at(i))));
        return complement(sum);
    }

    bool isCorrupt(Packet* packet) {
        return packet->checkSum != generateCheckSum(*packet->payload);
    }

    void corruptPacket(Packet* packet) {
        if ((rand() % 10 + 1) < 4) {
            packet->checkSum.erase(packet->checkSum.begin());
            packet->checkSum.erase(packet->checkSum.begin());
            packet->checkSum.erase(packet->checkSum.begin());
        }
    }

    void toReceiver(Packet* packet) {
        logSystem("AGUARDANDO ENVIO...");
        delayClock(DELAY);
        corruptPacket(packet);
        sharedPacket = packet;
        logSystem("PACOTE ENVIADO. AGUARDANDO ACK...");
    }

    void toSender(Packet* packet) {
        logSystem("AGUARDANDO ENVIO...");
        delayClock(DELAY);
        sharedPacket = packet;
        logSystem(sharedPacket->ack ? "ACK ENVIADO." : "NOT ACK ENVIADO.");
    }

    void sendAckAgain() {
        logSystem(sharedPacket->ack ? "AGUARDANDO REENVIO DO ACK..." : "AGUARDANDO REENVIO DO NAK...");
        delayClock(DELAY);
        logSystem(sharedPacket->ack ? "ACK REENVIADO." : "NOT ACK REENVIADO.");
    }

    void receiverAck() {
        if (isCorrupt(sharedPacket) || !sharedPacket->ack || sharedPacket->seqNum != ACTUAL_SEQNUM) {
            logSystem("PACOTE CORROMPIDO. ENVIANDO NOT ACK PARA O REMETENTE");
            delayClock(DELAY);
            sharedPacket->ack = false;
            toSender(sharedPacket);
        } else {
            logSystem("PACOTE CORRETO. ENVIANDO ACK PARA O REMETENTE");
            delayClock(DELAY);
            receivedMessage += *sharedPacket->payload;
            toSender(sharedPacket);
        }

        ACTUAL_SEQNUM = ACTUAL_SEQNUM == 1 ? 0 : 1;
    }
}

#endif //RDT_TRANSPORT_H
