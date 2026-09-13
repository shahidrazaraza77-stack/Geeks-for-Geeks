class Solution {
  public:
    int partyHouse(vector<vector<int>> &adj) {
        int n = adj.size();

        // BFS helper to find farthest node and its distance
        auto bfs = [&](int start) {
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;
            int farNode = start;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    v--; // adjust since adj is 1-indexed in input
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        if (dist[v] > dist[farNode]) {
                            farNode = v;
                        }
                    }
                }
            }
            return make_pair(farNode, dist[farNode]);
        };

        // Step 1: BFS from any node (say 0)
        auto [A, _] = bfs(0);

        // Step 2: BFS from A to find diameter
        auto [B, diameter] = bfs(A);

        // Step 3: Minimum possible max distance
        return (diameter + 1) / 2;
    }
};
