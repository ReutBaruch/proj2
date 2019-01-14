#include "MyClientHandler.h"
#include <unistd.h>
#include <string.h>
#include <string>

template <>
MyClientHandler<string, string>::MyClientHandler(CacheManager<string, string>* cacheMan,
        Solver<string, string>* solve){
    this->cacheManager = cacheMan;
    this->solver = solve;
}

template <>
void MyClientHandler<string, string>::handleClient(int newSockFD) {
    char buffer[1025];
    int n;
    string problem = "";
    string solution;
    //read the matrix
    bzero(buffer, 1025);
    n = read(newSockFD, buffer, 1024);
    do {
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        cout << "read:";
        cout << buffer << endl;

        problem += string(buffer);
        problem += ";";
        bzero(buffer, 1025);
        n = read(newSockFD, buffer, 1024);
    } while (strcmp(buffer, "end") != 0);
    //put the "end"
    problem += string(buffer);
    problem += ";";

    //start position
    bzero(buffer, 1025);
    n = read(newSockFD, buffer, 1024);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    cout << "read:";
    cout << buffer << endl;

    problem += string(buffer);
    problem += ";";

    //end position
    bzero(buffer, 1025);
    n = read(newSockFD, buffer, 1024);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    cout << "read:";
    cout << buffer << endl;

    problem += string(buffer);

    if (this->cacheManager->haveSolution(problem)) {
        solution = this->cacheManager->getSolution(problem);
    } else {
        solution = this->solver->solve(problem);
        printf("solve\n");
        this->cacheManager->saveSolution(solution, problem);
    }

    char *bufferWrite = const_cast<char *>(solution.c_str());

    n = write(newSockFD, bufferWrite, 1024);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    cout << "write:" << endl;
    cout << bufferWrite << endl;
  //  close(newSockFD);
}