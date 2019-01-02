#ifndef PROJ2_SOLVER_H
#define PROJ2_SOLVER_H

//#include "Problem.h"
//#include "Solution.h"

template <class Problem, class Solution>
class Solver{

public:
    virtual Solution solve(Problem problem) = 0;
};

#endif //PROJ2_SOLVER_H
