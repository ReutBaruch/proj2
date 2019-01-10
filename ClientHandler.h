#ifndef PROJ2_CLIENTHANDLER_H
#define PROJ2_CLIENTHANDLER_H

#include <iostream>
#include <fstream>

class ClientHandler{

public:
    virtual void handleClient(int newSockFd) = 0;
};

#endif //PROJ2_CLIENTHANDLER_H
