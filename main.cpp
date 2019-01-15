#include <iostream>
#include "Server.h"
#include "MyParallerServer.h"
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
#include "MyClientHandler.h"
#include "StartMain.h"
#include <string>
#include <string.h>

using namespace server_side;
using namespace std;



int main(int argc, char* argv[]){

    boot::StartMain* run = new boot::StartMain();
    run->main(argc, argv);

    delete (run);


    return 0;
}