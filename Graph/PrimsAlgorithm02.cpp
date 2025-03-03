#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    // Function to find the sum of weights of edges of the Minimum Spanning Tree
    int spanningTree(int V, vector<vector<int> > adj[]) {
        // Priority queue to store {weight, node, parent}
        priority_queue<vector<int>, 
                       vector<vector<int> >, 
                       greater<vector<int> > > pq;

        vector<int> vis(V, 0);  // Visited array
        vector<pair<int, int> > mstEdges;  // To store the edges of MST
        int sum = 0;

        // Start from node 0 with weight 0 and parent -1
        vector<int> tmp(3);
        tmp[0] = 0;
        tmp[1] = 0;
        tmp[2] = -1;
        pq.push(tmp);

        while (!pq.empty()) {
            int wt = pq.top()[0];
            int node = pq.top()[1];
            int parent = pq.top()[2];
            //auto [wt, node, parent] = pq.top();
            pq.pop();

            if (vis[node]) continue;

            // Mark the node as visited and add its weight to the sum
            vis[node] = 1;
            sum += wt;

            // Store valid edge if parent exists
            if (parent != -1) {
                mstEdges.push_back(make_pair(parent, node));
            }

            // Explore adjacent nodes
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edW = it[1];

                if (!vis[adjNode]) {
                    tmp[0] = edW;
                    tmp[1] = adjNode;
                    tmp[2] = node;
                    pq.push(tmp);
                }
            }
        }

        // Print the MST edges
        cout << "MST Edges:\n";
        for (auto e : mstEdges) {
            int u = e.first;
            int v = e.second;
            cout << u << " - " << v << endl;
        }

        return sum;
    }
};

int main() {
    int V = 5;
    vector<int> tmp(3);
    vector<vector<int> > edges;
    tmp[0] = 0;
    tmp[1] = 1;
    tmp[2] = 2;
    edges.push_back(tmp);
    tmp[0] = 0;
    tmp[1] = 2;
    tmp[2] = 1;
    edges.push_back(tmp);
    tmp[0] = 1;
    tmp[1] = 2;
    tmp[2] = 1;
    edges.push_back(tmp);
    tmp[0] = 2;
    tmp[1] = 3;
    tmp[2] = 2;
    edges.push_back(tmp);
    tmp[0] = 3;
    tmp[1] = 4;
    tmp[2] = 1;
    edges.push_back(tmp);
    tmp[0] = 4;
    tmp[1] = 2;
    tmp[2] = 2;
    edges.push_back(tmp);
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