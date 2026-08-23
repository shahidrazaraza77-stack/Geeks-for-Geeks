class Solution {
  public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        if (mat[r][c] == '#')
            return 0;

        // dist[i][j] = minimum upward moves needed to reach (i,j)
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        deque<pair<int,int>> dq;
        dq.push_front({r, c});
        dist[r][c] = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; k++) {
                int nx = x + dr[k];
                int ny = y + dc[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if (mat[nx][ny] == '#')
                    continue;

                int extraUp = (nx < x) ? 1 : 0;
                int newUp = dist[x][y] + extraUp;

                if (newUp > u)
                    continue;

                if (newUp < dist[nx][ny]) {
                    dist[nx][ny] = newUp;

                    if (extraUp)
                        dq.push_back({nx, ny});
                    else
                        dq.push_front({nx, ny});
                }
            }
        }

        int ans = 0;

        // For every reachable cell:
        // down moves = up moves + row_difference
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dist[i][j] == INT_MAX)
                    continue;

                int downMoves = dist[i][j] + (i - r);

                if (downMoves <= d)
                    ans++;
            }
        }

        return ans;
    }
};