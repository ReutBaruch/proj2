cmake_minimum_required(VERSION 3.13)
project(proj2)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj2 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h Solver.h MyTestClientHandler.cpp MyTestClientHandler.h InputStream.cpp InputStream.h OutputStream.cpp OutputStream.h Problem.cpp Problem.h Solution.cpp Solution.h CacheManager.cpp CacheManager.h)