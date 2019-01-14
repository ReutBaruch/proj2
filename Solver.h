#ifndef PROJ2_SOLVER_H
#define PROJ2_SOLVER_H

template <class Problem, class Solution>
class Solver{

public:
    virtual Solution solve(Problem problem) = 0;
    virtual ~Solver(){};
};

#endif //PROJ2_SOLVER_H
