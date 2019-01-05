#include <iostream>
#include "Server.h"
#include "MySerialServer.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include "FileCacheManager.h"
#include "StringReverse.h"

using namespace server_side;
int main() {
    CacheManager<string, string>* cacheManager = new FileCacheManager<string, string>();
    Solver<string, string>* solver = new StringReverse();
    ClientHandler* clientHandler = new MyTestClientHandler<string, string>(cacheManager, solver);
    Server* server = new MySerialServer();
    server->open(5400, clientHandler);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}