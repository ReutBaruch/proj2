#include "MySerialServer.h"
#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <functional>
#include <vector>
#include <pthread.h>
#include <time.h>

#define WAIT_FOR_CLIENT 60;

struct socketArgs {
//    template <class InputStream, class OutputStream>
    int newsockfd;
    int clilen;
    int sockfd;
    struct sockaddr_in cli_addr;
    ClientHandler* clientHandler;
};

void* runClient(void* args){
    timeval timeout;
    timeout.tv_sec = WAIT_FOR_CLIENT;
    timeout.tv_usec = 0;

    struct socketArgs* param = (struct socketArgs*) args;

    while(true) {
        setsockopt(param->sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));
        /* Accept actual connection from the client */
        param->newsockfd = accept(param->sockfd, (struct sockaddr *) &(param->cli_addr),
                                  (socklen_t *) &(param->clilen));
        if (param->newsockfd < 0) {
            if (errno == EWOULDBLOCK){
                printf("timeout\n");
                exit(2);
            } else {
                perror("ERROR on accept");
                exit(1);
            }
        }
        printf("connected\n");
        param->clientHandler->handleClient(param->newsockfd);
        printf("serverrr\n");
//        param->clientHandler->handleClient(param->newsockfd);
        close(param->newsockfd);
    }
}

void MySerialServer::open(int port, ClientHandler* client){

    int sockfd, newsockfd, portno, clilen;

    struct sockaddr_in serv_addr, cli_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((uint16_t)((size_t)portno));

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection*/
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    struct socketArgs* arg = new socketArgs();

    arg->cli_addr = cli_addr;
    arg->clilen = clilen;
    arg->newsockfd = newsockfd;
    arg->sockfd = sockfd;
    arg->clientHandler = client;

    pthread_t pthread;
    pthread_create(&pthread, nullptr, runClient, arg);
    pthread_join(pthread, NULL);

    this->stop(sockfd);
};

void MySerialServer::stop(int sockfd){
    close(sockfd);
}


