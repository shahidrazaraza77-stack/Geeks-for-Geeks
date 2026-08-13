#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        vector<int> indegree(V, 0);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            indegree[v]++;
        }
        
        // Step 2: Topological sort (Kahn’s algorithm)
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (auto &p : adj[u]) {
                int v = p.first;
                if (--indegree[v] == 0) q.push(v);
            }
        }
        
        // Step 3: Initialize distances
        vector<int> dist(V, INT_MIN);
        dist[src] = 0;
        
        // Step 4: Relax edges in topological order
        for (int u : topo) {
            if (dist[u] != INT_MIN) {
                for (auto &p : adj[u]) {
                    int v = p.first, w = p.second;
                    dist[v] = max(dist[v], dist[u] + w);
                }
            }
        }
        
        return dist;
    }
};
