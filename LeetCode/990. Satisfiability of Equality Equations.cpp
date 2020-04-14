//
// Created by heisenberg on 4/13/20.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char Find(char node, map<char, char> &parents) {
        if (node == parents[node]) {
            return parents[node];
        }
        return parents[node] = Find(parents[node], parents);
    }

    void Union(char a, char b, map<char, char> &parents) {
        char parA, parB;
        parA = Find(a, parents);
        parB = Find(b, parents);
        if (parA == parB) {
            return;
        }
        parents[parA] = parB;
    }

    void makeset(map<char, char> &parents) {
        for (char c = 'a'; c <= 'z'; c++) {
            parents[c] = c;
        }
    }

    bool equationsPossible(vector<string> &equations) {
        map<char, char> parents;
        makeset(parents);
        for (int i = 0; i < equations.size(); i++) {
            string eq = equations[i];
            char a, b;
            a = eq[0];
            b = eq[3];
            char op = eq[1];
            if (op == '=') {
                Union(a, b, parents);
            }
        }

        for (int i = 0; i < equations.size(); i++) {
            string eq = equations[i];
            char a, b;
            a = eq[0];
            b = eq[3];
            char op = eq[1];
            if (op == '!') {
                char parA = Find(a, parents);
                char parB = Find(b, parents);

                if (parA == parB) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<string> v{"f==a", "a==b", "f!=e", "a==c", "b==e", "c==f"};
    Solution s;

    cout << s.equationsPossible(v) << endl;
}