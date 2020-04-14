//
// Created by heisenberg on 4/12/20.
//


#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;

/*
 *  equations = [ ["a", "b"], ["b", "c"] ],
    values = [2.0, 3.0],
    queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
 */

class Node {
public:
    string node;
    double val;

    Node(string s, double v) {
        node = s;
        val = v;
    }
};

class Solution {
public:
    void makeset(vector<vector<string>> &equations, map<string, string> &parent, map<string, double> &val) {
        for (int i = 0; i < equations.size(); i++) {
            //  eqn -> a/b=2.0
            string a, b;
            a = equations[i][0];
            b = equations[i][1];

            parent[a] = a;
            parent[b] = b;

            val[a] = 1.0;
            val[b] = 1.0;
        }
    }

    string Find(string node, map<string, string> &parent) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = Find(parent[node], parent);
    }

    void Union(string a, string b, double ratio, map<string, string> &parent) {
        string parentA = Find(a, parent);
        string parentB = Find(b, parent);

        if (parentA == parentB) {
            return;
        }
        parent[a] = parentB;
    }


    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        map<string, string> parent;
        map<string, double> val;

        makeset(equations, parent, val);

        for (int i = 0; i < equations.size(); i++) {
            //  eqn -> a/b=2.0
            string a, b;
            a = equations[i][0];
            b = equations[i][1];
        }
    }
};