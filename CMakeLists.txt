cmake_minimum_required(VERSION 3.10)
project(ProblemSolving)

set(CMAKE_CXX_STANDARD 11)

add_executable(Beatles Codeforces/Round-549-Div2-1143-D-The\ Beatles.cpp Offline/cryptoOffline.cpp Offline/cryptoHeader.h "LightOJ/1276 - Very Lucky Numbers.cpp" "LightOJ/1307-Counting Triangles.cpp")
add_executable(cryptoOffline1 Offline/cryptoOffline.cpp)
add_executable(LOJ-1276 LightOJ/1276\ -\ Very\ Lucky\ Numbers.cpp)
add_executable(LOJ-1307 LightOJ/1307-Counting\ Triangles.cpp)