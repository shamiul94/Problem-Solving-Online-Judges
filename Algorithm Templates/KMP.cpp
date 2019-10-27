/**
@author - Rumman BUET CSE'15
Problem -
Idea -
Concept -
*/

#include <bits/stdc++.h>

using namespace std;


/************************************** END OF INITIALS ****************************************/

int LPS[100000] = {};
int N;

void generateLPSArray(string pattern) {
    N = static_cast<int>(pattern.length());
    int j, i;
    // initialize
    j = 0;
    LPS[0] = 0;

    for (i = 1; i < N;) {
        if (pattern[j] == pattern[i]) {
            LPS[i] = j + 1;
            i++;
            j++;
        } else { // pattern[j] != pattern[i]
            if (j > 0) {
                j = LPS[j - 1];
            } else {
                LPS[i] = 0;
                i++;
            }
        }
    }
}




int main() {
    string pattern = "aabaaaabaax";
    generateLPSArray(pattern);
    for (char i : pattern) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < pattern.length(); i++) {
        cout << LPS[i] << " ";
    }
    cout << endl;
    return 0;
}