#include "ServerController.h"
#include <sstream>

void ServerController::handleClient(SOCKET clientSocket) {
    char buffer[BUFFER_SIZE];
    std::string currentUser = "";

    while (true) {
        int bytes = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytes <= 0) break;

        buffer[bytes] = '\0';
        std::string cmd(buffer);
        std::stringstream ss(cmd);
        std::string action;
        ss >> action;

        if (action == "LOGIN") {
            ss >> currentUser;
            model.addUser(currentUser);
            send(clientSocket, "OK\n", 3, 0);
        }
        else if (action == "SEND") {
            std::string to;
            ss >> to;
            std::string msg;
            getline(ss, msg);
            model.addMessage(to, { currentUser, msg });
            send(clientSocket, "OK\n", 3, 0);
        }
        else if (action == "CHECK") {
            if (model.hasMessages(currentUser))
                send(clientSocket, "YES\n", 4, 0);
            else
                send(clientSocket, "NO\n", 3, 0);
        }
        else if (action == "RECEIVE") {
            if (model.hasMessages(currentUser)) {
                Message m = model.getMessage(currentUser);
                std::string out = "FROM " + m.sender + ":" + m.content + "\n";
                send(clientSocket, out.c_str(), out.size(), 0);
            }
            else {
                send(clientSocket, "EMPTY\n", 6, 0);
            }
        }
        else if (action == "LOGOUT") {
            currentUser = "";
            send(clientSocket, "OK\n", 3, 0);
        }
    }

    closesocket(clientSocket);
}
