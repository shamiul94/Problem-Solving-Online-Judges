//
// Created by heisenberg on 3/31/20.
//

#include <bits/stdc++.h>

using namespace std;

#define UNVISITED -1
#define VISITED 1

class Solution {
public:

    int endNode;

    void
    dfs(vector<vector<int>> &graph, int currNode, vector<int> &path, vector<int> &visited, vector<vector<int>> &res) {
        if (currNode == endNode) {
            res.emplace_back(path);
            return;
        }

        visited[currNode] = VISITED;
        for (int i = 0; i < graph[currNode].size(); i++) {
            int v = graph[currNode][i];
            if (visited[v] == UNVISITED) {
                path.emplace_back(v);
                dfs(graph, v, path, visited, res);
                path.pop_back();
            }
        }
        visited[currNode] = UNVISITED;
   }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        endNode = graph.size() - 1;
        vector<int> visited(20, -1);
        vector<vector<int>> res;
        vector<int> path;
        path.emplace_back(0);
        dfs(graph, 0, path, visited, res);
        return res;
    }
};