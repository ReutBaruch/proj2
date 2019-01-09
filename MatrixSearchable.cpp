#include "MatrixSearchable.h"
/*
template <class T>
MatrixSearchable<T>::MatrixSearchable(){
    this->rowCount = 0;
}

template <class T>
State<T> MatrixSearchable<T>::getInitialState(){
    return this->initialState;
}

template <class T>
State<T> MatrixSearchable<T>::getGoalState(){
    this->goalState;
}

template <class T>
State<T> MatrixSearchable<T>::getStateByIndex(int row, int col) {
    return this->matrix[row][col];
}

template <class T>
list<State<T>> MatrixSearchable<T>::getAllPossibleStates(State<T> state){

}

template<class T>
void MatrixSearchable<T>::addRowToMatrix(string row) {
    vector<State<T>> rowVector;
    double cost;
    int col = 0;

    char *temp = const_cast<char *>(row.c_str());
    temp = strtok(temp, ",");

    while (strcmp(temp, "") != 0) {
        cost = atof(temp);
        temp = strtok(NULL, ",");

        State<std::string> newState = new State<std::string>();
        string name = to_string(this->countRow) + "," + to_string(col);

        newState.setState(name);
        newState.setCost(cost);
        rowVector.push_back(newState);

        col++;
    }

    this->matrix.push_back(rowVector);
    this->rowCount++;
}

template<class T>
void MatrixSearchable<T>::createMatrix(string newMatrixString) {

    setGoalState(this->getStateByIndex(i, j));
}

template<class T>
string MatrixSearchable<T>::fromListTostringPath(list<State<T>> list){
    //TODO
    return "zcdsc";
}*/