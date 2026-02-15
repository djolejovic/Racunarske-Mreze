#include "ClientController.h"

bool ClientController::connectToServer() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    return connect(sock, (sockaddr*)&server, sizeof(server)) == 0;
}

void ClientController::run() {
    char buffer[BUFFER_SIZE];

    while (true) {
        std::string cmd;
        std::getline(std::cin, cmd);

        send(sock, cmd.c_str(), cmd.size(), 0);

        int bytes = recv(sock, buffer, BUFFER_SIZE, 0);
        buffer[bytes] = '\0';
        std::cout << buffer;
    }
}
