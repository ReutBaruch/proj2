#ifndef PROJ2_BFS_H
#define PROJ2_BFS_H

#include "Searcher.h"
#include <unordered_set>
#include <list>
#include <string.h>
#include "BackTrace.h"

using namespace std;

template <class Solution, class T>
class BFS: public Searcher<Solution, T> {
    int nodesEvaluated;
    BackTrace<T>* back;
    double cost;

public:
    BFS(){
        this->nodesEvaluated = 0;
    }

    double getCost(){
        return this->cost;
    }

    virtual ~BFS(){};

    string search(Searchable<T>* toSearch){
        list<State<T>*> open;
        unordered_set<State<T>*> openHash;
        unordered_set<State<T>*> close;
        list<State<T>*> backTraceList;
        State<T>* goal = toSearch->getGoalState();

        open.push_back(toSearch->getInitialState());
        openHash.insert(toSearch->getInitialState());

        while(!open.empty()){
            State<T>* state = open.front();
            open.pop_front();
            openHash.erase(state);
            close.insert(state);
            this->nodesEvaluated++;

            if(state->equals(goal)){
                return this->back->backTrace(state, toSearch, cost);
            }

            list<State<T>*> succerssors = toSearch->getAllPossibleStates(state);

            while (!succerssors.empty()){
                State<T>* temp = succerssors.front();
                succerssors.pop_front();
                if ((!close.count(temp)) && (!openHash.count(temp))){
                    open.push_back(temp);
                    temp->setParent(state);
                    openHash.insert(temp);
                } else if (openHash.count(temp)){
                    temp->setParent(state);
                    close.insert(temp);
                    openHash.erase(temp);
                }
            }
        }
        printf("No route found.");
        return "-1";
    }

    int getNumberOfNodesEvaluated(){
        return this->nodesEvaluated;
    }
};


#endif //PROJ2_BFS_H
