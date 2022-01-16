#ifndef RDT_APPLICATION_H
#define RDT_APPLICATION_H

#include <iostream>
#include "Transport.h"

namespace Application {

    /**
     * Alice é o Remetente
     *
     * Este procedimento inicia a transferência de pacotes para o destinatário.
     */
    void Alice() {
        std::string message = "abcdef";
        logAlice("Alice esta tentando enviar a mensagem \"" + message + "\" para Bob...");
        Transport::sendMessage(message);
    }

    /**
     * Bob é o Destinatário
     *
     * Este procedimento inicia o processo de recebimento dos pacotes.
     */
    void Bob() {
        string returnedMessage = Transport::receiveMessage();
        logBob("Bob recebeu a mensagem: " + returnedMessage);
    }
}


#endif //RDT_APPLICATION_H
