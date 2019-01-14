#ifndef PROJ2_STARTMAIN_H
#define PROJ2_STARTMAIN_H

#include "MyParallerServer.h"
#include <string.h>
#include <stdio.h>
#include "Searchable.h"
#include "Searcher.h"
#include "Solver.h"
#include "MyClientHandler.h"
#include "CacheManager.h"
#include "MatrixSolver.h"
#include "Astar.h"
#include "FileCacheManager.h"


namespace boot{
    class StartMain{
    public:
        ~StartMain(){};
        int main(int argc, char* argv[]) {
            if(argc != 2){
                printf("Invalid input");
                exit(4);
            }
            int port = stoi(argv[1]);
            Server* myServer = new MyParallerServer();
            Searcher<string, string>* searcher = new Astar<string, string>();
            Solver<string, string>* solver = new
                    MatrixSolver<string, string, string>(searcher);
            CacheManager<string, string>* cache = new FileCacheManager<string, string>();
            ClientHandler* client = new MyClientHandler<string, string>(cache, solver);
            cout << "start server" << endl;
            myServer->open(port, client);
            cout << "sever end" << endl;

            delete myServer;
            delete searcher;
            delete solver;
            delete cache;
            delete client;

            return 0;
        }
    };
}


#endif //PROJ2_STARTMAIN_H
