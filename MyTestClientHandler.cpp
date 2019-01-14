#include "MyTestClientHandler.h"
#include <string.h>
#include <unistd.h>

template <>
MyTestClientHandler<string, string>::MyTestClientHandler(CacheManager<string, string>* cacheM,
        Solver<string, string>* solve){
    this->cacheManager = cacheM;
    this->solver = solve;

}

template <>
void MyTestClientHandler<string, string>::handleClient(int newSockFD) {
    char buffer[1025];
    int n;
    string problem, solution;
    while (true) {
        bzero(buffer, 1025);
        n = read(newSockFD, buffer, 1024);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        problem = string(buffer);

        if (strcmp(buffer, "end") == 0) {
            return;
        }

        if (this->cacheManager->haveSolution(problem)) {
            solution = this->cacheManager->getSolution(problem);
        } else {
            solution = this->solver->solve(problem);
            this->cacheManager->saveSolution(solution, problem);
        }

        char bufferWrite[1024];
        bzero(bufferWrite, 1025);
        strcpy(bufferWrite, solution.c_str());
        ssize_t nBuffer = write(newSockFD, bufferWrite, strlen(bufferWrite));

        if (nBuffer < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }
}
