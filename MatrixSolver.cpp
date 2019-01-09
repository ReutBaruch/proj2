/*#include "MatrixSolver.h"

template <class Problem, class Solution, class T>
MatrixSolver<Problem, Solution, T>::MatrixSolver(Searcher<Solution, T>* search){
    this->searcher = search;
}

template <class Problem, class Solution, class T>
string MatrixSolver<Problem, Solution, T>::solve(string problem){
    MatrixSearchable<T>* matrix = new MatrixSearchable<T>();
    matrix->createMatrix(problem);
    list<State<T>> backTrace;
    backTrace = this->searcher->search(matrix);

    string result = matrix->fromListTostringPath(backTrace);

    return result;
}*/