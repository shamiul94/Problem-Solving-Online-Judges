cmake_minimum_required(VERSION 3.10)
project(ProblemSolving)

set(CMAKE_CXX_STANDARD 11)

#add_executable(a1138 "LightOJ/1138-Trailing Zeroes (III).cpp" "InterviewBit/Add One To Number.cpp" "LeetCode/950. Reveal Cards In Increasing Order.cpp" "LeetCode/969. Pancake Sorting.cpp" Codechef/CHFPARTY.cpp "LeetCode/1051. Height Checker.cpp" "LeetCode/665. Non-decreasing Array.cpp" "LeetCode/985. Sum of Even Numbers After Queries.cpp" "LeetCode/929. Unique Email Addresses.cpp")

#add_executable(des Offline/DES.h Offline/DES.cpp)
#add_executable(transpose Offline/Transposition.cpp)

add_executable(manacher "Algorithm Templates/Euler Path - Hierholzer Algorithm.cpp")
add_executable(leet "LeetCode/23. Merge k Sorted Lists.cpp")
add_executable(codeforces "Codeforces/1277-D. Let's Play the Words?.cpp")
add_executable(leet2 "Online Judge Templates/my_template.h" "LeetCode/1129. Shortest Path with Alternating Colors.cpp")
#add_executable(testerr Testing/testing.cpp)


add_executable(tsttrr Testing/testin2.cpp)
add_executable(kmp "Algorithm Templates/KMP.cpp")

