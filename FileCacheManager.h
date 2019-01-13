#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H

#include <map>
#include "CacheManager.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;
template <class Problem, class Solution>
class FileCacheManager: public CacheManager<Problem, Solution>{
    map <string, string> problemsAndSolutions;

public:
    FileCacheManager(){
        this->readFile();
    }

    void readFile(){
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

    void writeFile(){
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
    virtual bool haveSolution(string problem){
        if (this->problemsAndSolutions.count(problem)){
            printf("chace\n");
            return true;
        }
        else {
            return false;
        }
    }

    virtual string getSolution(string problem){
        return this->problemsAndSolutions.find(problem)->second;
    }
    virtual void saveSolution(string solution, string problem){
        this->problemsAndSolutions.insert(pair<string, string>(problem, solution));
    }

    ~FileCacheManager(){
        writeFile();
    }

};


#endif //PROJ2_FILECACHEMANAGER_H
