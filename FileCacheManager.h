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
        string problem = "";
        string solution = "";
        if(myFile.is_open()){
            while (getline(myFile, line)){
                char* c = const_cast<char*>(line.c_str());
                c = strtok(c, "$");
                problem += c;

                c = strtok(NULL, ";");
                solution += c;

                this->problemsAndSolutions.insert(pair<string, string>(problem, solution));
            }
            myFile.close();
        }
    }

    void writeFile(string problem, string solution){
        ofstream myFile("ProbAndSolv.txt", ios::app);
        string line;

        if(myFile.is_open()){
            myFile << problem ;
            myFile << "$";
            myFile << solution;
            myFile <<"\n";
        }
    }
    virtual bool haveSolution(string problem){
        if (this->problemsAndSolutions.count(problem)){
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
        writeFile(problem, solution);
    }

    virtual ~FileCacheManager(){};

};


#endif //PROJ2_FILECACHEMANAGER_H
