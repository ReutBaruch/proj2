#ifndef PROJ2_CLIENTHANDLER_H
#define PROJ2_CLIENTHANDLER_H

#include <iostream>
#include <fstream>
//#include "InputStream.h"
//#include "OutputStream.h"

//template <class InputStream, class OutputStream>
class ClientHandler{

public:
    virtual void handleClient(int newSockFd) = 0;
};

#endif //PROJ2_CLIENTHANDLER_H
