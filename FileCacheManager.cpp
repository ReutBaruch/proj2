/*#include "FileCacheManager.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

template <>
void FileCacheManager<string, string>::writeFile() {
    ofstream myFile("ProbAndSolv.txt", ios::trunc);
    string line;
    string problem, solution;
    if(myFile.is_open()){
        map<string, string>::iterator it;
        for(it = this->problemsAndSolutions.begin(); it != this->problemsAndSolutions.end(); it++){
            myFile << (*it).first ;
            myFile << ";";
            myFile << (*it).second;
            myFile <<"\n";
        }
    }
}


template <>
void FileCacheManager<string, string>::readFile(){
    ifstream myFile("ProbAndSolv.txt");
    string line;
    string problem, solution;
    if(myFile.is_open()){
        while (getline(myFile, line)){
            char* c = const_cast<char*>(line.c_str());
            problem = strtok(c, ";");
            solution = strtok(NULL, ";");
            this->problemsAndSolutions.insert(pair<string, string>(problem, solution));
        }
    }
}

template <>
FileCacheManager<string, string>::FileCacheManager(){
    this->readFile();
}

template <>
bool FileCacheManager<string, string>::haveSolution(string problem){
    if (this->problemsAndSolutions.count(problem)){
        printf("chace\n");
        return true;
    }
    else {
        return false;
    }
}

template <>
string FileCacheManager<string, string>::getSolution(string problem){
    return this->problemsAndSolutions.find(problem)->second;
}

template <>
void FileCacheManager<string, string>::saveSolution(string solution, string problem){
    this->problemsAndSolutions.insert(pair<string, string>(problem, solution));
}

template <>
FileCacheManager<string, string>::~FileCacheManager() {
    writeFile();
}*/