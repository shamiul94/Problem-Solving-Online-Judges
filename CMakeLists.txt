cmake_minimum_required(VERSION 3.10)
project(ProblemSolving)

set(CMAKE_CXX_STANDARD 11)

#add_executable(a1138 "LightOJ/1138-Trailing Zeroes (III).cpp" "InterviewBit/Add One To Number.cpp" "LeetCode/950. Reveal Cards In Increasing Order.cpp" "LeetCode/969. Pancake Sorting.cpp" Codechef/CHFPARTY.cpp "LeetCode/1051. Height Checker.cpp" "LeetCode/665. Non-decreasing Array.cpp" "LeetCode/985. Sum of Even Numbers After Queries.cpp" "LeetCode/929. Unique Email Addresses.cpp")

#add_executable(des Offline/DES.h Offline/DES.cpp)
#add_executable(transpose Offline/Transposition.cpp)

add_executable(manacher "Algorithm Templates/Manacher's Algorithm.cpp")
add_executable(leet "LeetCode/155. Min Stack.cpp")
#add_executable(testerr Testing/testing.cpp)


add_executable(tsttrr Testing/testin2.cpp)
add_executable(kmp "Algorithm Templates/KMP.cpp")

