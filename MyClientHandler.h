#ifndef PROJ2_MYCLIENTHANDLER_H
#define PROJ2_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include <string>
#include "CacheManager.h"
#include "Solver.h"

template <class Problem, class Solution>
class MyClientHandler: public ClientHandler{
    CacheManager<string, string>* cacheManager;
    Solver<string, string>* solver;

public:
    MyClientHandler(CacheManager<string, string>* cacheManager, Solver<string, string>* solver);
    virtual void handleClient(int newSockFD);
    virtual ~MyClientHandler(){};

};


#endif //PROJ2_MYCLIENTHANDLER_H
