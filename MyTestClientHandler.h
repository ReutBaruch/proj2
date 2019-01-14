#ifndef PROJ2_MYTESTCLIENTHANDLER_H
#define PROJ2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

template <class Problem, class Solution>
class MyTestClientHandler : public ClientHandler {
    CacheManager<string, string>* cacheManager;
    Solver<string, string>* solver;

public:
    MyTestClientHandler(CacheManager<string, string>* cacheManager, Solver<string, string>* solver);
    virtual void handleClient(int newSockFD);
    virtual ~MyTestClientHandler(){};

};


#endif //PROJ2_MYTESTCLIENTHANDLER_H
