#include "Common.h"
#include "ServerController.h"
#include <thread>

void runServer() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET server = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server, (sockaddr*)&addr, sizeof(addr));
    listen(server, SOMAXCONN);

    std::cout << "Server pokrenut...\n";

    ServerController controller;

    while (true) {
        SOCKET client = accept(server, nullptr, nullptr);
        std::thread(&ServerController::handleClient, &controller, client).detach();
    }

    closesocket(server);
    WSACleanup();
}
