#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicates(const vector<int> &arr1, const vector<int> &arr2) {
    // your code goes here
    int i = 0, j = 0; // pointers
    int M = arr1.size();
    int N = arr2.size();

    vector<int> v;
    // for similar size - M == N

    // O(M) == O(N) --> O(N) -- similar length
    // M==2, N==10000

    // arr1 = [100000,200000]
    // arr2 = [ 1, 2 ,3 , 4....... 1000]

    //
    //
    // space - O(commonNums) - O(min(M,N))
    // O(max(M,N))
    while (i <= M - 1 && j <= N - 1) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else if (arr1[i] == arr2[j]) {
            v.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return v;
}
/*
arr1 = [1,  2,  3,  5,  6, 7],
           i                       i 
arr2 = [3,  6,  7,  8,  20]
           j             j 
                        
// arr1 = [100000,200000]
                   i 
// arr2 = [ 1,2 ,3 , 4....... 1000] --->  O(N)

ans = [3 , 6, 7]
*/
// arr1 = [ 1, 2, 3, 5, 6, 7, 8, 9, ......., 60 ] i = M - 1 arr2 = [3, 60] j

int main() {
    return 0;
}