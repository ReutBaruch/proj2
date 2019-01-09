#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H


//TODO nodeState
template <class T>
class State {
    T state;
    double cost;
    State<T>* parent;

public:
    State(){
        this->cost = 0;
    }

    double getCost(){
        return this->cost;
    }

    bool equals(State<T>* s){
        if (this->state == s->getState()){
            return true;
        } else {
            return false;
        }
    }

    State<T>* getParent(){
        return this->parent;
    }

    T getState(){
        return this->state;
    }

    void setParent(State<T>* parent1){
        this->parent = parent1;
    }

    void setState(T state1){
        this->state = state1;
    }

    void setCost(int cost1){
        this->cost = cost1;
    }
};


#endif //PROJ2_STATE_H
