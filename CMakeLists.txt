cmake_minimum_required(VERSION 3.13)
project(proj2)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-std=c++14 -pthread")

add_executable(proj2 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h Solver.h MyTestClientHandler.cpp MyTestClientHandler.h InputStream.cpp InputStream.h OutputStream.cpp OutputStream.h CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverse.cpp StringReverse.h State.h Searchable.h Searcher.h BFS.cpp BFS.h)