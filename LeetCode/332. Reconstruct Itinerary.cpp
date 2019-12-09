#include <bits/stdc++.h>

using namespace std;

// Hierholzer's Algorithm (https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/)
// to find out Euler Circuit.
// 62%, 100%

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {

        /*
         *  JFK -> ATL SFO
            JFK ->
            SFO -> ATL
            ATL -> JFK SFO
            ATL ->
         */

        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
//        unordered_map<string, priority_queue<string, std::vector<string>>> adj;
        int N = static_cast<int>(tickets.size());

        for (int i = 0; i < N; i++) {
            string from, to;
            from = tickets[i][0];
            to = tickets[i][1];
            adj[from].push(to);
        }

        string currNode = "JFK";
        string nextNode;

        stack<string> curr_path;
        vector<string> circuit;

        // push the first node in the stack curr_path.
        curr_path.push(currNode);
        while (!curr_path.empty()) {
            if (!adj[currNode].empty()) { // we can go further from this node. we have more edges from here.
                nextNode = adj[currNode].top();
                adj[currNode].pop(); // deleting the edge.
                curr_path.push(nextNode);
                currNode = nextNode;
            } else { // I am stuck at some node, no more edge from here.
                circuit.push_back(currNode);
                curr_path.pop();
                if (curr_path.empty()) break;
                currNode = curr_path.top();
            }
        }

        reverse(circuit.begin(), circuit.end());
        return circuit;
    }
};

int main() {
    Solution s;
    vector<vector<string>> v{{"JFK", "SFO"},
                             {"JFK", "ATL"},
                             {"SFO", "ATL"},
                             {"ATL", "JFK"},
                             {"ATL", "SFO"}};
    vector<string> t = s.findItinerary(v);

//    for (int i = 0; i < t.size(); i++) {
//        cout << t[i] << endl;
//    }
    return 0;
}

/*
 *["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is
 ["JFK","SFO","ATL","JFK","ATL","SFO"].
 */
