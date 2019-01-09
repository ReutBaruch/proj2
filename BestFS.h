#ifndef PROJ2_BESTFS_H
#define PROJ2_BESTFS_H

#include <unordered_set>
#include <list>
#include <string.h>

template <class Solution, class T>
class BestFS: public Searcher<Solution, T> {
    int nodesEvaluated;

public:
    BestFS(){
        this->nodesEvaluated = 0;
    }

    int getNumberOfNodesEvaluated(){
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

    list<State<T>*> sort(list<State<T>*> open, State<T>* state){
        list<State<T>*> result;
        State<T>* stateOpen;
        while(!open.empty()){
            stateOpen = open.front();
            open.pop_front();
            if (stateOpen->getCost() >= state->getCost()){
                result.push_back(state);
                break;
            } else {
                result.push_back(stateOpen);
            }
        }
        while(!open.empty()){
            stateOpen = open.front();
            open.pop_front();
            result.push_back(stateOpen);
        }

        return result;
    }

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
                this->nodesEvaluated++;
                return this->backTrace(state, toSearch);
            }

            list<State<T>*> succerssors = toSearch->getAllPossibleStates(state);

            while (!succerssors.empty()){
                State<T>* temp = succerssors.front();
                succerssors.pop_front();
                if ((!close.count(temp)) && (!openHash.count(temp))){
                    open.push_back(temp);
                    temp->setParent(state);
                    openHash.insert(temp);
                    temp->setCost(temp->getCost() + state->getCost());
                    open = sort(open, temp);
                } else if (openHash.count(temp)){
                    temp->setParent(state);
                    close.insert(temp);
                    this->nodesEvaluated++;
                    openHash.erase(temp);
                }
            }
        }
    }

};


#endif //PROJ2_BESTFS_H
