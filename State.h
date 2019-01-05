#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H

template <class T>
class State {
    T state;
    double cost;
    State<T> parent;

public:
    virtual bool equals(State<T> s);
};


#endif //PROJ2_STATE_H
