#ifndef PROJ2_BESTFS_H
#define PROJ2_BESTFS_H

#include <unordered_set>
#include <list>
#include <string.h>
#include "BackTrace.h"

template <class Solution, class T>
class BestFS: public Searcher<Solution, T> {
    int nodesEvaluated;
    BackTrace<T>* back;

public:
    BestFS(){
        this->nodesEvaluated = 0;
    }

    int getNumberOfNodesEvaluated(){
        return this->nodesEvaluated;
    }


    list<State<T>*> sort(list<State<T>*> open, State<T>* state){
        list<State<T>*> result;
        State<T>* stateOpen;
        if (open.empty()){
           result.push_back(state);
        } else {
            stateOpen = open.front();
            open.pop_front();
            if (stateOpen->getCost() >= state->getCost()){
                result.push_back(state);
            } else {
                result.push_back(stateOpen);
            }
        }

        return result;
    }

    string search(Searchable<T>* toSearch){
        list<State<T>*> open;
        unordered_set<State<T>*> close;
        list<State<T>*> backTraceList;
        State<T>* goal = toSearch->getGoalState();

        open.push_back(toSearch->getInitialState());

        while(!open.empty()){
            State<T>* state = open.front();
            open.pop_front();
            close.insert(state);
            this->nodesEvaluated++;

            if(state->equals(goal)){
                return this->back->backTrace(state, toSearch);
            }

            list<State<T>*> succerssors = toSearch->getAllPossibleStates(state);

            while (!succerssors.empty()){
                State<T>* temp = succerssors.front();
                succerssors.pop_front();
                if (!close.count(temp)){
                    temp->setParent(state);
                    open = sort(open, temp);
                }
            }
        }
        printf("No route found.");
        exit(3);
    }

};


#endif //PROJ2_BESTFS_H
