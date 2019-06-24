cmake_minimum_required(VERSION 3.10)
project(ProblemSolving)

set(CMAKE_CXX_STANDARD 11)

#add_executable(a1138 "LightOJ/1138-Trailing Zeroes (III).cpp" "InterviewBit/Add One To Number.cpp" "LeetCode/950. Reveal Cards In Increasing Order.cpp" "LeetCode/969. Pancake Sorting.cpp" Codechef/CHFPARTY.cpp "LeetCode/1051. Height Checker.cpp" "LeetCode/665. Non-decreasing Array.cpp" "LeetCode/985. Sum of Even Numbers After Queries.cpp" "LeetCode/929. Unique Email Addresses.cpp")

add_executable(des Offline/DES.h Offline/DES.cpp)
add_executable(transpose Offline/Transposition.cpp)

#add_executable(painful "LightOJ/1021 - Painful Bases.cpp")
#add_executable(testerr Testing/testing.cpp)

