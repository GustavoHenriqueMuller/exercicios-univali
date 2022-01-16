#include "Network/Application.h"

using namespace std;

int main() {
    srand(time(nullptr));

    logMenu();

    // Primeiro, faremos Alice enviar uma mensagem para Bob.
    Application::Alice();

    // Agora, veremos se bob receberá esta mensagem.
    Application::Bob();

    return 0;
}