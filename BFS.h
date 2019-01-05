#ifndef PROJ2_BFS_H
#define PROJ2_BFS_H

#include "Searcher.h"

template <class Solution, class T>
class BFS: public Searcher<Solution, T> {

    virtual Solution search(Searchable<T> toSearch);
    virtual int getNumberOfNodesEvaluated();

};


#endif //PROJ2_BFS_H
