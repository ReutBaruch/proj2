#ifndef PROJ2_CACHEMANAGER_H
#define PROJ2_CACHEMANAGER_H

#include "Problem.h"
#include "Solution.h"
#include <map>

using namespace std;

class CacheManager {
    map <Problem, Solution> problemsAndSolutions;

public:
    virtual bool haveSolution(Problem problem) = 0;
    virtual Solution getSolution(Problem problem) = 0;
    virtual void saveSolution(Solution solution, Problem problem) = 0;
};


#endif //PROJ2_CACHEMANAGER_H
