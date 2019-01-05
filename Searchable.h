#ifndef PROJ2_SEARCHABLE_H
#define PROJ2_SEARCHABLE_H

#include "State.h"
#include <list>

using namespace std;
template <class T>
class Searchable{
    State<T> start;
    State<T> goal;

public:
    virtual State<T> getInitialState() = 0;
    virtual State<T> getGoalState() = 0;
    virtual list<State<T>> getAllPossibleStates(State<T> state) = 0;

};

#endif //PROJ2_SEARCHABLE_H
