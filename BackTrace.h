#ifndef PROJ2_BACKTRACE_H
#define PROJ2_BACKTRACE_H

#include <string>
#include <string.h>
#include "State.h"
#include "Searchable.h"
#include <stdio.h>

template <class T>
class BackTrace{

public:

    ~BackTrace(){};
    string backTrace(State<T>* goal, Searchable<T>* toSearch, double &cost) {
        State<T> *start = toSearch->getInitialState();
        string result = "";
        list<State<T> *> backTraceList;
        cost = goal->getCost();

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
            cost += goal->getCost();
        }

        result = result.substr(2);

        return result;
    }
};

#endif //PROJ2_BACKTRACE_H
