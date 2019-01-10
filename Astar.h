#ifndef PROJ2_ASTAR_H
#define PROJ2_ASTAR_H

#include "Searcher.h"
#include <unordered_set>
#include <list>
#include <string.h>

template <class Solution, class T>
class Astar: public Searcher<Solution, T> {
    int nodesEvaluated;

public:
    Astar() {
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

    string search(Searchable<T>* toSearch){
        list<State<T>*> open;
        map<State<T>*, double> costHash;
        list<State<T>*> backTraceList;
        State<T>* goal = toSearch->getGoalState();

        string name = goal->getState();
        char* divide = const_cast<char *>(name.c_str());
        int goalI = stoi(strtok(divide, ","));
        int goalJ = stoi(strtok(NULL, ","));

        open.push_back(toSearch->getInitialState());
        costHash.insert(pair<State<T>*, double>(toSearch->getInitialState(), toSearch->getInitialState()->getCost()));

        while(!open.empty()){
            State<T>* state = open.front();
            open.pop_front();
            double stateCost = costHash.find(state)->second;
            this->nodesEvaluated++;

            if(state->equals(goal)){
                this->nodesEvaluated++;
                return this->backTrace(state, toSearch);
            }

            list<State<T>*> succerssors = toSearch->getAllPossibleStates(state);

            while (!succerssors.empty()){
                State<T>* temp = succerssors.front();
                succerssors.pop_front();

                string nameTemp = temp->getState();
                char* divideTemp = const_cast<char *>(nameTemp.c_str());
                int tempI = stoi(strtok(divideTemp, ","));
                int tempJ = stoi(strtok(NULL, ","));

                double h = abs(tempI - goalI) + abs(tempJ - goalJ);
                double g = temp->getCost() + stateCost;
                double newCost = h + g;

                if (costHash.count(temp)) {
                    double preCost = costHash.find(temp)->second;
                    if (newCost < preCost){
                        temp->setParent(state);
                        costHash.insert(pair<State<T>*, double>(temp, newCost));
                    }
                } else {
                    open.push_back(temp);
                    temp->setParent(state);
                    costHash.insert(pair<State<T>*, double>(temp, newCost));
                }
            }
        }
    }
};

#endif //PROJ2_ASTAR_H
