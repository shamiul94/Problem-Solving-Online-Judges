#include <iostream>
#include <vector>

using namespace std;

/*
 *

      1 2 3 5 6 7 6 3 2 0 0 0 0 0 0 0 0 ---> 1 2 3 5 6 7 6 3 2 0 0 0 0 0 0 0 0
lo -                    ^
hi -                                   ^

*/


// just make a simple simulation of this problem. you will get it.
vector<int> moveZerosToEnd(const vector<int> &arr) {
    // your code goes here
    vector<int> A;
    A = arr;
    int n = A.size();

    int lo = 0, hi;
    for (hi = 0; hi < n; hi++) {
        if (A[hi] == 0) {
            if (A[lo] != 0) {
                lo = hi; // initialize lo. till now it wasn't initialized to any valid point.
            }
            continue;
        }

        // here is another intersting thing:
        // what if no zero?
        // 1 2 3 4
        // lo and hi both will increase every time.
        // so, lo and hi will always will be the same.
        // every time same element will be swapped with itself.
        // although it's waste of time, but it's O(1) so, we don't care.

        swap(A[lo], A[hi]);
        lo++;
    }

    return A;
}

int main() {
    vector<int> A{0, 1};
    vector<int> B = moveZerosToEnd(A);
    for (int i = 0; i < B.size(); i++) {
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}
