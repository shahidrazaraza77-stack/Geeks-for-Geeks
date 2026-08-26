class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        vector<int> dist(V, 0);

        for (int i = 0; i < V; i++) {
            bool updated = false;

            for (auto &e : edges) {
                int u = e[0], v = e[1], w = e[2];

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    updated = true;

                    if (i == V - 1)
                        return true;
                }
            }

            if (!updated)
                break;
        }

        return false;
    }
};