#ifndef PROJ2_MYSERIALSERVER_H
#define PROJ2_MYSERIALSERVER_H

#include "Server.h"

using namespace server_side;
class MySerialServer: public Server{
    bool runner=true;

public:
    virtual void open(int port,ClientHandler* clientHandler);
    virtual bool stop(int sockfd);
};


#endif //PROJ2_MYSERIALSERVER_H
