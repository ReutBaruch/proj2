#include <iostream>
#include "Server.h"
#include "MySerialServer.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include "FileCacheManager.h"
#include "StringReverse.h"
#include "MatrixSolver.h"
#include "MatrixSearchable.h"
#include "Searcher.h"
#include "BFS.h"
#include "BestFS.h"
#include "Astar.h"

using namespace server_side;
//using namespace std;

int main() {
    Searcher<string, string>* searcher = new BestFS<string, string>();
    Solver<string, string>* solver = new
            MatrixSolver<string, string, string>(searcher);
    Searcher<string, string>* searcher2 = new BFS<string, string>();
    Solver<string, string>* solver2 = new
            MatrixSolver<string, string, string>(searcher2);
    Searcher<string, string>* searcher3 = new Astar<string, string>();
    Solver<string, string>* solver3 = new
            MatrixSolver<string, string, string>(searcher3);
    //string result = solver->solve("1,2;4,5;end;0,0;1,1");

    string result = solver->solve("9,8,7;6,5,4;3,20,1;end;0,0;2,2");
    string result2 = solver2->solve("9,8,7;6,5,4;3,20,1;end;0,0;2,2");
    string result3 = solver3->solve("1,2;3,4;end;0,0;1,1");
    //string result2 = solver2->solve("1,2,3;4,5,6;7,8,9;end;0,0;2,2");
    std::cout << "BestFS: " + result << std::endl;
    std::cout << "BFS: " + result2 << std::endl;
    std::cout << "Astar: " + result3 << std::endl;
    //ClientHandler* clientHandler = new MyTestClientHandler<string, string>(cacheManager, solver);
   // Server* server = new MySerialServer();
    //server->open(5400, clientHandler);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}