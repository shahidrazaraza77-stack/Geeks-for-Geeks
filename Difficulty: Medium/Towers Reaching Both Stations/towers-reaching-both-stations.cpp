class Solution {
  public:
    void dfs(int i, int j, vector<vector<int>> &mat,
             vector<vector<bool>> &vis) {

        int n = mat.size(), m = mat[0].size();
        vis[i][j] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                !vis[ni][nj] &&
                mat[ni][nj] >= mat[i][j]) {

                dfs(ni, nj, mat, vis);
            }
        }
    }

    int countCoordinates(vector<vector<int>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> P(n, vector<bool>(m, false));
        vector<vector<bool>> Q(n, vector<bool>(m, false));

        // Station P (Top row)
        for (int j = 0; j < m; j++)
            if (!P[0][j]) dfs(0, j, mat, P);

        // Station P (Left column)
        for (int i = 0; i < n; i++)
            if (!P[i][0]) dfs(i, 0, mat, P);

        // Station Q (Bottom row)
        for (int j = 0; j < m; j++)
            if (!Q[n - 1][j]) dfs(n - 1, j, mat, Q);

        // Station Q (Right column)
        for (int i = 0; i < n; i++)
            if (!Q[i][m - 1]) dfs(i, m - 1, mat, Q);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (P[i][j] && Q[i][j])
                    ans++;
            }
        }

        return ans;
    }
};