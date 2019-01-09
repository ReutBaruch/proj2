#include "DFS.h"
#include <bits/unordered_set.h>

template <class Solution, class T>
Solution DFS<Solution, T>::search(Searchable<T> toSearch){
    list<State<T>> solu;
    list<State<T>> open;
    unordered_set<State<T>> openVis;
    unordered_set<State<T>> close;
    open.push_back(toSearch.getInitialState());
    while(!open.empty()){
        State<T> state = open.front();
        solu.insert(state);
        close.insert(state, 1);
        openVis.insert(state, 1);
        this->nodesEvaluated++;
        if(state.equals(toSearch.getGoalState())){
            this->nodesEvaluated++;
            return solu;
        }
        list<State<T>> successors = toSearch.getAllPossibleStates(state);
        while (!succerssors.empty()) {
            State<T> temp = succerssors.front();
            if(!openVis.count(tmep)){
                openVis.insert(temp, 1);
                search(temp);
            }
        }
        open.push_back(temp);
    }
}

template <class Solution, class T>
int DFS<Solution, T>::getNumberOfNodesEvaluated(){
    return this->nodesEvaluated;
}
