#include "MyTestClientHandler.h"

template <class Problem, class Solution, class InputStream, class OutputStream>
void MyTestClientHandler<Problem, Solution, InputStream, OutputStream>
        ::handleClient(InputStream inputStream, OutputStream outputStream){
    if (to_string(inputStream) != "end"){
        if (this->cacheManager->haveSolution(inputStream)){
            outputStream = this->cacheManager->getSolution(inputStream);
        } else {
            outputStream = this->solver->solve(inputStream);
            this->cacheManager->saveSolution(outputStream, inputStream);
        }
    } else { //TODO: close the connection
        outputStream = "close";
    }
}
