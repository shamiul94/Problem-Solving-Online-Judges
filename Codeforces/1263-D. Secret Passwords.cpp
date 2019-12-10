//
// Created by shamiul93 on 12/11/19.
//

#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

using namespace std;

int N;

class Node {
public:
    char parent;
    int rank;

    Node(char p, int r) {
        parent = p;
        rank = r;
    }
};

char find(vector<Node> &Nodes, char currNodeChar) {
    // find root and make root as parent of i (path compression)
    int idx = currNodeChar - 'a';

    // if my parent is not me, i can compress it.
    if (Nodes[idx].parent != currNodeChar) {
        Nodes[idx].parent = find(Nodes, Nodes[idx].parent);
    }

    // if my parent is me myself, i don't have anything else to do
    return Nodes[idx].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(vector<Node> &Nodes, char x, char y) {
    char xParent = find(Nodes, x);
    char yParent = find(Nodes, y);

    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (Nodes[xParent - 'a'].rank < Nodes[yParent - 'a'].rank) {
        Nodes[xParent - 'a'].parent = yParent;
    } else if (Nodes[xParent - 'a'].rank > Nodes[yParent - 'a'].rank) {
        Nodes[yParent - 'a'].parent = xParent;
    } else {
        // If ranks are same, then make one as root and increment
        // its rank by one
        Nodes[yParent - 'a'].parent = xParent;
        Nodes[xParent - 'a'].rank++;
    }
}


int main() {
//    fi;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<Node> Nodes;

    for (int i = 0; i < 26; i++) {
        Nodes.emplace_back(static_cast<char>('a' + i), 0);
    }

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
//        scanf("%s", &s);
        auto len = static_cast<int>(s.length());
        char x, y;
        x = s[0];
        for (int j = 0; j < len; j++) {
            y = s[j];
            Union(Nodes, x, y);
        }
    }

    unordered_set<char> Set;
    for (int i = 0; i < Nodes.size(); i++) {
//        cout << (char) ('a' + i) << " -> "
//             << Nodes[i].parent << " , " << Nodes[i].rank << endl;
        if (Nodes[i].rank != 0) {
            Set.insert(Nodes[i].parent);
        }
    }
    cout << Set.size() << endl;

    return 0;
}