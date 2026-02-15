#pragma once
#include "Common.h"

class ClientController {
public:
    bool connectToServer();
    void run();

private:
    SOCKET sock;
};
#pragma once
