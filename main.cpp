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
#include "DFS.h"

using namespace server_side;
using namespace std;

int main() {

   // string tryy = "0,0,0,0;90,4,5,0;0,7,8,90;0,6,7,0;end;0,0;3,3";
    //string tryy = "1,2,1,3,4;4,1,6,3,6;2,0,9,2,3;2,8,9,6,12;3,5,6,8,23;end;0,0;3,3";
  /*   string tryy = "1,2;1,3;end;0,0;1,1";
    Searcher<string, string>* searcher22 = new DFS<string, string>();
    Solver<string, string>* solver22 = new
            MatrixSolver<string, string, string>(searcher22);
    string gf = solver22->solve(tryy);
    cout << "DFS path: " + gf << endl;
    int rresult = searcher22->getNumberOfNodesEvaluated();
    cout << "DFS tryy: " + to_string(rresult) << endl;

*/
    int result;
    string matrix = "";
    Searcher<string, string>* searcher = new BFS<string, string>();
    Solver<string, string>* solver = new
            MatrixSolver<string, string, string>(searcher);

    for (int i = 0; i < 10; i++){
        for (int i = 0; i < 9; i++){
            matrix += to_string(i)+",";
        }
        matrix += "9;";
    }
    matrix +="end;0,0;9,9";
    solver->solve(matrix);
    result = searcher->getNumberOfNodesEvaluated();
    cout << "BFS 10: " + to_string(result) << endl;

    matrix = "";
    for (int i = 0; i < 13; i++){
        for (int i = 0; i < 12; i++){
            matrix += to_string(i)+",";
        }
        matrix += "12;";
    }
    matrix +="end;0,0;12,12";
    Searcher<string, string>* searcher13 = new Astar<string, string>();
    Solver<string, string>* solver13 = new
            MatrixSolver<string, string, string>(searcher13);
    solver13->solve(matrix);
    result = searcher13->getNumberOfNodesEvaluated();
    cout << "Astar 13: " + to_string(result) << endl;

    matrix = "";
    for (int i = 0; i < 15; i++){
        for (int i = 0; i < 14; i++){
            matrix += to_string(i)+",";
        }
        matrix += "14;";
    }
    matrix +="end;0,0;14,14";
    Searcher<string, string>* searcher1 = new Astar<string, string>();
    Solver<string, string>* solver1 = new
            MatrixSolver<string, string, string>(searcher1);
    solver1->solve(matrix);
    result = searcher1->getNumberOfNodesEvaluated();
    cout << "Astar 15: " + to_string(result) << endl;

    matrix = "";
    for (int i = 0; i < 20; i++){
        for (int i = 0; i < 19; i++){
            matrix += to_string(i)+",";
        }
        matrix += "19;";
    }
    matrix +="end;0,0;19,19";
    Searcher<string, string>* searcher2 = new Astar<string, string>();
    Solver<string, string>* solver2 = new
            MatrixSolver<string, string, string>(searcher2);
    solver2->solve(matrix);
    result = searcher2->getNumberOfNodesEvaluated();
    cout << "Astar 20: " + to_string(result) << endl;

    matrix = "";
    for (int i = 0; i < 25; i++){
        for (int i = 0; i < 24; i++){
            matrix += to_string(i)+",";
        }
        matrix += "24;";
    }
    matrix +="end;0,0;24,24";
    Searcher<string, string>* searcher3 = new Astar<string, string>();
    Solver<string, string>* solver3 = new
            MatrixSolver<string, string, string>(searcher3);
    solver3->solve(matrix);
    result = searcher3->getNumberOfNodesEvaluated();
    cout << "Astar 25: " + to_string(result) << endl;

    matrix = "";
    for (int i = 0; i < 30; i++){
        for (int i = 0; i < 29; i++){
            matrix += to_string(i)+",";
        }
        matrix += "29;";
    }
    matrix +="end;0,0;29,29";
    Searcher<string, string>* searcher4 = new Astar<string, string>();
    Solver<string, string>* solver4 = new
            MatrixSolver<string, string, string>(searcher4);
    solver4->solve(matrix);
    result = searcher4->getNumberOfNodesEvaluated();
    cout << "Astar 30: " + to_string(result) << endl;

    matrix = "";
    for (int i = 0; i < 35; i++){
        for (int i = 0; i < 34; i++){
            matrix += to_string(i)+",";
        }
        matrix += "34;";
    }
    matrix +="end;0,0;34,34";
    Searcher<string, string>* searcher5 = new Astar<string, string>();
    Solver<string, string>* solver5 = new
            MatrixSolver<string, string, string>(searcher5);
    solver5->solve(matrix);
    result = searcher5->getNumberOfNodesEvaluated();
    cout << "Astar 35: " + to_string(result) << endl;

    matrix = "";
    for (int i = 0; i < 40; i++){
        for (int i = 0; i < 39; i++){
            matrix += to_string(i)+",";
        }
        matrix += "39;";
    }
    matrix +="end;0,0;39,39";
    Searcher<string, string>* searcher6 = new Astar<string, string>();
    Solver<string, string>* solver6 = new
            MatrixSolver<string, string, string>(searcher6);
    solver6->solve(matrix);
    result = searcher6->getNumberOfNodesEvaluated();
    cout << "Astar 40: " + to_string(result) << endl;

    matrix = "";
    for (int i = 0; i < 45; i++){
        for (int i = 0; i < 44; i++){
            matrix += to_string(i)+",";
        }
        matrix += "44;";
    }
    matrix +="end;0,0;44,44";
    Searcher<string, string>* searcher7 = new Astar<string, string>();
    Solver<string, string>* solver7 = new
            MatrixSolver<string, string, string>(searcher7);
    solver7->solve(matrix);
    result = searcher7->getNumberOfNodesEvaluated();
    cout << "Astar 45: " + to_string(result) << endl;

    matrix = "";
    for (int i = 0; i < 50; i++){
        for (int i = 0; i < 49; i++){
            matrix += to_string(i)+",";
        }
        matrix += "49;";
    }
    matrix +="end;0,0;49,49";
    Searcher<string, string>* searcher8 = new Astar<string, string>();
    Solver<string, string>* solver8 = new
            MatrixSolver<string, string, string>(searcher8);
    solver8->solve(matrix);
    result = searcher8->getNumberOfNodesEvaluated();
    cout << "Astar 50: " + to_string(result) << endl;

    return 0;
}