#include "../Online Judge Templates/my_template.h"

#define RED 0
#define BLUE 1
#define NO_COLOR 2

#define PII pair<int,int>

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges) {

        // pair -> first = num , second = prev edge color
        vector<PII > adj[n];

        PII p;

        int rN = static_cast<int>(red_edges.size()), bN = static_cast<int>(blue_edges.size());

        for (int i = 0; i < rN; i++) {
            int u, v, color; // u to v
            u = red_edges[i][0];
            v = red_edges[i][1];
            color = RED;
            adj[u].emplace_back(make_pair(v, color));
        }

        for (int i = 0; i < bN; i++) {
            int u, v, color; // u to v
            u = blue_edges[i][0];
            v = blue_edges[i][1];
            color = BLUE;
            adj[u].emplace_back(make_pair(v, color));
        }

        // This is the most important lesson in this problem.
        // when edges are different colors, we need something to differntiate them from the others.
        // we did it here by using 2-d arrays.
        vector<vector<bool>> visited(n, vector<bool>(3, false)); // visited[n][3]
        vector<vector<int>> shortestPath(n, vector<int>(3, -1)); // shortedPath[n][3]


        queue<PII > q;
        q.push(make_pair(0, NO_COLOR)); // start with 0 and no color
        visited[0][RED] = true; // red == 0
        visited[0][BLUE] = true; // blue == 1
        visited[0][NO_COLOR] = true; // no color == 2

        shortestPath[0][RED] = 0;
        shortestPath[0][BLUE] = 0;
        shortestPath[0][NO_COLOR] = 0;

        while (!q.empty()) {
            PII uNode = q.front(), vNode;
            q.pop();

            int u = uNode.first, v;
            int prevEdgeColor = uNode.second;
            // first = node no , second = prev edge color
            if (prevEdgeColor == NO_COLOR) {
                for (int i = 0; i < adj[u].size(); i++) {
                    vNode = adj[u][i];
                    visited[vNode.first][vNode.second] = true;
                    shortestPath[vNode.first][vNode.second] = 1;
                    q.push(vNode);
                }
            } else if (prevEdgeColor == BLUE) {
                for (int i = 0; i < adj[u].size(); i++) {
                    vNode = adj[u][i];
                    if (vNode.second == RED && visited[vNode.first][RED] == false) {
                        visited[vNode.first][RED] = true;
                        shortestPath[vNode.first][RED] = shortestPath[uNode.first][prevEdgeColor] + 1;
                        q.push(vNode);
                    }
                }
            } else if (prevEdgeColor == RED) {
                for (int i = 0; i < adj[u].size(); i++) {
                    vNode = adj[u][i];
                    if (vNode.second == BLUE && visited[vNode.first][BLUE] == false) {
                        visited[vNode.first][BLUE] = true;
                        shortestPath[vNode.first][BLUE] = shortestPath[uNode.first][prevEdgeColor] + 1;
                        q.push(vNode);
                    }
                }
            }
        }
        vector<int> ans;
        ans.push_back(0); // 0 will always have distance 0 cause we start from this node.
        for (int i = 1; i < n; i++) {
            int redVal, blueVal;
            redVal = shortestPath[i][0];
            blueVal = shortestPath[i][1];
            if (redVal == -1 && blueVal == -1) {
                ans.push_back(-1);
            } else if (redVal == -1) {
                ans.push_back(blueVal);
            } else if (blueVal == -1) {
                ans.push_back(redVal);
            } else {
                ans.push_back(min(redVal, blueVal));
            }
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector<vector<int>> v{{0, 1},
                          {1, 1},
                          {1, 3}};
    vector<vector<int>> t{{0, 2},
                          {1, 1},
                          {2, 2},
                          {2, 3}};
    vector<int> vv = s.shortestAlternatingPaths(4, v, t);
    for (int i = 0; i < vv.size(); i++) {
        cout << vv[i] << " ";
    }
    cout << endl;
    return 0;
}



//Example 1:
//
//Input: n = 3, red_edges = {{0,1},{1,2}}, blue_edges = {}
//Output: {0,1,-1}
//Example 2:
//
//Input: n = 3, red_edges = {{0,1}}, blue_edges = {{2,1}}
//        Output: {0,1,-1}
//Example 3:
//
//Input: n = 3, red_edges = {{1,0}}, blue_edges = {{2,1}}
//        Output: {0,-1,-1}
//Example 4:
//
//Input: n = 3, red_edges = {{0,1}}, blue_edges = {{1,2}}
//        Output: {0,1,2}
//Example 5:
//
//Input: n = 3, red_edges = {{0,1},{0,2}}, blue_edges = {{1,0}}
//        Output: {0,1,1}
