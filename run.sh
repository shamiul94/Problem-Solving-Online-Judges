rm -rf running.o
file="LeetCode/55. Jump Game.cpp"
# file="Rohan/prefix-postfix.c"
g++ -W -Wall -pedantic -o running.o -p "$file"
# g++ -o running.o "$file"
# gcc -o running.o "$file"
./running.o
# rm -rf running.o

#########################################################
# -W: Print extra warning messages for some problems.
# -Wall: Enable all the warnings about questionable code
# -pedantic: Show all the warnings demanded by strict ISO compliance
# -o programName: place the executable output in programName sourceFile.cpp: the 
# name of our source code file
# -p: Generate extra code to write profile information suitable for the analysis program prof
