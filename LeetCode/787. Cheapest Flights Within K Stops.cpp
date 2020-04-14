#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int nodeName;
    int srcDistance;
    int steps;

    Node(int name, int srcdist, int step) {
        nodeName = name;
        srcDistance = srcdist;
        steps = step;
    }
};

bool operator<(const Node &n1, const Node &n2) {
    return n1.srcDistance < n2.srcDistance;
}

class Solution {
public:
    int dijkstra(vector<int> &distanceFromSource, vector<int> adj[], vector<int> Cost[], int src, int dst, int K) {
        priority_queue<Node> pq;
        pq.push(Node(src, 0, -1));
        distanceFromSource[src] = 0;

        while (!pq.empty()) {
            Node u = pq.top();
            pq.pop();

            for (int i = 0; i < adj[u.nodeName].size(); i++) {
                Node v(adj[u.nodeName][i], INT_MAX, u.steps + 1);
                if (distanceFromSource[u.nodeName] + Cost[u.nodeName][i] < distanceFromSource[v.nodeName]
                    && u.steps + 1 <= K) {
                    distanceFromSource[v.nodeName] = distanceFromSource[u.nodeName] + Cost[u.nodeName][i];
                    v.srcDistance = distanceFromSource[v.nodeName];
                    pq.push(v);
                }
            }
        }

        return distanceFromSource[dst] == INT_MAX ? -1 : distanceFromSource[dst];
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        vector<int> adj[n];
        vector<int> Cost[n];
        vector<int> distanceFromSource(n, INT_MAX);

        for (int i = 0; i < flights.size(); i++) {
            int a = flights[i][0];
            int b = flights[i][1];
            int cost = flights[i][2];

            adj[a].push_back(b);
            Cost[a].push_back(cost);
        }
        return dijkstra(distanceFromSource, adj, Cost, src, dst, K);
    }
};