#ifndef PROJ2_CLIENTHANDLER_H
#define PROJ2_CLIENTHANDLER_H

#include <iostream>
#include <fstream>

class ClientHandler{

public:
    virtual void handleClient(int newSockFd) = 0;
    virtual ~ClientHandler(){};
};

#endif //PROJ2_CLIENTHANDLER_H
