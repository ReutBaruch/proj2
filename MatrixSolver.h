#ifndef PROJ2_MATRIXSOLVER_H
#define PROJ2_MATRIXSOLVER_H

#include "Solver.h"
#include "Searcher.h"
#include <string>
#include <list>
#include "MatrixSearchable.h"

template <class Problem, class Solution, class T>
class MatrixSolver: public Solver<Problem, Solution> {
    Searcher<Solution, T>* searcher;

public:
    MatrixSolver(Searcher<Solution, T>* search){
        this->searcher = search;
    }
    string solve(string problem){
        MatrixSearchable<T>* matrix = new MatrixSearchable<T>();
        matrix->createMatrix(problem);

        string result = this->searcher->search(matrix);

        return result;
    }
};


#endif //PROJ2_MATRIXSOLVER_H
