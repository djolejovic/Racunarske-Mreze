#pragma once
#include "MailboxModel.h"
#include "Common.h"

class ServerController {
public:
    void handleClient(SOCKET clientSocket);

private:
    MailboxModel model;
};
