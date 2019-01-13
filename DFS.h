#ifndef PROJ2_DFS_H
#define PROJ2_DFS_H

#include "Searcher.h"
#include "BackTrace.h"

using namespace std;
template <class Solution, class T>
class DFS: public Searcher<Solution, T> {
    int nodesEvaluated;
    BackTrace<T>* back;


public:
    DFS() {
        this->nodesEvaluated = 0;
    }

    int getNumberOfNodesEvaluated() {
        return this->nodesEvaluated;
    }


    string search(Searchable<T>* toSearch) {
        list<State<T>*> open;
        unordered_set<State<T>*> close;
        State<T>* state;
        State<T>* temp;
        State<T>* goal = toSearch->getGoalState();
        State<T>* start = toSearch->getInitialState();
        open.push_back(start);

        while (!open.empty()){
            state = open.front();
            open.pop_front();

            if(state->equals(goal)){
                return this->back->backTrace(state, toSearch);
            }

            if (!close.count(state)){
                close.insert(state);
                this->nodesEvaluated++;

                list<State<T>*> succerssors = toSearch->getAllPossibleStates(state);

                while (!succerssors.empty()){
                    temp = succerssors.front();
                    succerssors.pop_front();
                    if(close.count(temp))
                        continue;
                    temp->setParent(state);
                    open.push_back(temp);
                }
            }
        }
        printf("No route found.");
        exit(3);
    }

};

#endif //PROJ2_DFS_H
