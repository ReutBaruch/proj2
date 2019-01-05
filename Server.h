#ifndef PROJ2_SERVER_H
#define PROJ2_SERVER_H

#include "ClientHandler.h"

namespace server_side{
    class Server{

    public:

        virtual void open(int port,ClientHandler* clientHandler) = 0;
        virtual bool stop(int sockfd) = 0;
    };
}


#endif //PROJ2_SERVER_H
