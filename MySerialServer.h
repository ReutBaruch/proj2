#ifndef PROJ2_MYSERIALSERVER_H
#define PROJ2_MYSERIALSERVER_H

#include "Server.h"

using namespace server_side;
template <class InputStream, class OutputStream>
class MySerialServer {

public:
    virtual void open(int port,ClientHandler<InputStream, OutputStream>* clientHandler);
    virtual bool stop();

};


#endif //PROJ2_MYSERIALSERVER_H
