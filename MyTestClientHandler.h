#ifndef PROJ2_MYTESTCLIENTHANDLER_H
#define PROJ2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

template <class Problem, class Solution, class InputStream, class OutputStream>
class MyTestClientHandler : public ClientHandler<InputStream, OutputStream> {
    CacheManager* cacheManager;
    Solver<Problem, Solution>* solver;

public:
    virtual void handleClient(InputStream inputStream, OutputStream outputStream);

};


#endif //PROJ2_MYTESTCLIENTHANDLER_H
