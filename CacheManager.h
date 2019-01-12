#ifndef PROJ2_CACHEMANAGER_H
#define PROJ2_CACHEMANAGER_H

#include <map>

using namespace std;
template <class Problem, class Solution>
class CacheManager {
    map <Problem, Solution> problemsAndSolutions;

public:
    virtual bool haveSolution(Problem problem) = 0;
    virtual Solution getSolution(Problem problem) = 0;
    virtual void saveSolution(Solution solution, Problem problem) = 0;
    ~CacheManager(){};
};


#endif //PROJ2_CACHEMANAGER_H
