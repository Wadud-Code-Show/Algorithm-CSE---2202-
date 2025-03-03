#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    // Function to find the sum of weights of edges of the Minimum Spanning Tree
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Priority queue to store {weight, node, parent}
        priority_queue<tuple<int, int, int>, 
                       vector<tuple<int, int, int> >, 
                       greater<tuple<int, int, int> > > pq;

        vector<int> vis(V, 0);  // Visited array
        vector<pair<int, int> > mstEdges;  // To store the edges of MST
        int sum = 0;

        // Start from node 0 with weight 0 and parent -1
        pq.push({0, 0, -1});

        while (!pq.empty()) {
            auto [wt, node, parent] = pq.top();
            pq.pop();

            if (vis[node]) continue;

            // Mark the node as visited and add its weight to the sum
            vis[node] = 1;
            sum += wt;

            // Store valid edge if parent exists
            if (parent != -1) {
                mstEdges.push_back({parent, node});
            }

            // Explore adjacent nodes
            for (auto &it : adj[node]) {
                int adjNode = it[0];
                int edW = it[1];

                if (!vis[adjNode]) {
                    pq.push({edW, adjNode, node});
                }
            }
        }

        // Print the MST edges
        cout << "MST Edges:\n";
        for (auto [u, v] : mstEdges) {
            cout << u << " - " << v << endl;
        }

        return sum;
    }
};

int main() {
    int V = 5;
    vector<vector<int> > edges;
    edges.push_back({0, 1, 2});
    edges.push_back({0, 2, 1});
    edges.push_back({1, 2, 1});
    edges.push_back({2, 3, 2});
    edges.push_back({3, 4, 1});
    edges.push_back({4, 2, 2});
    vector<vector<int> > adj[V];

    for (auto &it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    Solution obj;
    int sum = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << sum << endl;

    return 0;
}
