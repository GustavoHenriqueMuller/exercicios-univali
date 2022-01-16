#ifndef RDT_COMMUNICATION_H
#define RDT_COMMUNICATION_H

#include "Network.h"
#include "Clock.h"

namespace Transport {

    const int MAX_DELAY = 3;

    bool corruptAck() {
        return ((rand() % 10 + 1) < 4);
    }

    void sendNakMessage() {
        do {
            Network::sendAckAgain();
        } while(corruptAck());
    }

    /**
     * Procedimento responsável por realizar o envio de mensagens do
     * remetente para o destinatário.
     */
    void sendMessage(std::string message) {
        int seqNum = 0;

        int packetAmount = ceil(message.length() / float(PAYLOAD_SIZE));
        logSystem("SERAO NECESSARIOS " + to_string(packetAmount) +  " PACOTES.");

        for(int packetNum = 0; packetNum < packetAmount; packetNum++) {
            std::string packetPayload;
            int length = message.length();

            for(int i = 0; i < ((PAYLOAD_SIZE < length) ? PAYLOAD_SIZE : length); i++) {
                packetPayload += message.at(0);
                message.erase(message.begin());
            }

            logSystem("ENVIANDO PACOTE " + to_string(packetNum + 1));

            // Criando o pacote que será enviado.
            Packet* packet = nullptr;

            // Realizando o envio do pacote do Remetente para o Destinatário.
            bool isAck = false;
            while (!isAck) {
                delete packet;
                packet = Network::createPacket(seqNum, true, Network::generateCheckSum(packetPayload), packetPayload);

                // Começa a contar a passagem do tempo logo antes de enviar o pacote.
                startClock();

                Network::toReceiver(packet);

                // Conta quanto tempo passou desde o envio do pacote.
                double time = stopClock();

                if (time >= MAX_DELAY) {
                    logSystem("TEMPO LIMITE DE " + to_string(MAX_DELAY) + "s EXCEDIDO. REENVIANDO O PACOTE.");

                } else {
                    Network::receiverAck();

                    if (corruptAck()) {
                        logSystem("ACK PACKET FOI CORROMPIDO. ENVIANDO NAK.");
                        sendNakMessage();
                    }

                    isAck = sharedPacket->ack;
                    if (!isAck) {
                        logSystem("NOT ACK RECEBIDO. REENVIANDO PACOTE.");
                    } else {
                        logSystem("ACK RECEBIDO.");
                    }
                }
            }

            seqNum = seqNum == 1 ? 0 : 1;
            logSystem("PACOTE " + to_string((packetNum + 1)) + " ENVIADO COM SUCESSO.\n");
        }
    }

    /**
     * Procedimento responsável por realizar o recebimento da mensagem.
     */
    std::string receiveMessage() {
        return receivedMessage;
    }
}

#endif //RDT_COMMUNICATION_H
