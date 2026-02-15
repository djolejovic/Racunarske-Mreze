#include "ClientController.h"
#include <iostream>

void runClient() {
    ClientController client;

    if (!client.connectToServer()) {
        std::cout << "Neuspesna konekcija\n";
        return;
    }

    std::cout << "Povezan sa serverom\n";
    std::cout << "Komande: LOGIN, SEND, CHECK, RECEIVE, LOGOUT\n";

    client.run();
}
