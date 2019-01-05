#include "BFS.h"
#include <bits/unordered_set.h>

template <class Solution, class T>
Solution BFS<Solution, T>::search(Searchable<T> toSearch){
    list<State<T>> open;
    list<State<T>> close;
    list<T> backTrace;
    open.push_back(toSearch.getInitialState());
    while(!open.empty()){
        State<T> state = open.pop_back();
        close.push_back(state);
        if(state.equals(toSearch.getGoalState())){
            return backTrace;
        }
        list<State<T>> succerssors = toSearch.getAllPossibleStates(state);
        while (!succerssors.empty()){
            State<T> temp = succerssors.front();

        }
    }
}

template <class Solution, class T>
int BFS<Solution, T>::getNumberOfNodesEvaluated(){

}
