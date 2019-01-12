#ifndef PROJ2_DFS_H
#define PROJ2_DFS_H

#include "Searcher.h"

using namespace std;
template <class Solution, class T>
class DFS: public Searcher<Solution, T> {
    int nodesEvaluated;

public:
    DFS() {
        this->nodesEvaluated = 0;
    }

    int getNumberOfNodesEvaluated() {
        return this->nodesEvaluated;
    }


    string backTrace(State<T>* goal, Searchable<T>* toSearch) {
        State<T> *start = toSearch->getInitialState();
        string result = "";
        list<State<T> *> backTraceList;

        while (!goal->equals(start)) {
            string name = goal->getState();
            string parentName = goal->getParent()->getState();

            char *divide = const_cast<char *>(name.c_str());
            int childI = stoi(strtok(divide, ","));
            int childJ = stoi(strtok(NULL, ","));

            char *divideParent = const_cast<char *>(parentName.c_str());
            int parentI = stoi(strtok(divideParent, ","));
            int parentJ = stoi(strtok(NULL, ","));

            if (childI > parentI) {
                result = "Down" + result;
            } else if (childI < parentI) {
                result = "Up" + result;
            } else if (childJ > parentJ) {
                result = "Right" + result;
            } else if (childJ < parentJ) {
                result = "Left" + result;
            }

            result = ", " + result;

            goal = goal->getParent();
        }

        result = result.substr(2);

        return result;
    }

    void recursive(State<T>* state,unordered_set<State<T>*> close, Searchable<T>* searchable) {
        list<State<T>*> successors;
        this->nodesEvaluated++;
        State<T>* temp;

        if (state->equals(searchable->getGoalState())){
            return;
        }
        successors = searchable->getAllPossibleStates(state);
        while (!successors.empty()) {
            temp = successors.front();
            successors.pop_front();
            if (!close.count(temp)){// && (!temp->equals(searchable->getGoalState()))) {
                close.insert(temp);
                temp->setParent(state);
                recursive(temp, close, searchable);
                //this->nodesEvaluated++;
            }
        }
      //  recursive(temp, close, searchable);
    }

    /*string search(Searchable<T>* toSearch) {
        unordered_set<State<T>*> close;
        State<T>* start = toSearch->getInitialState();
        close.insert(start);
        this->recursive(start,close,toSearch);
        return this->backTrace(toSearch->getGoalState(), toSearch);
    }*/

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
                return this->backTrace(state, toSearch);
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
