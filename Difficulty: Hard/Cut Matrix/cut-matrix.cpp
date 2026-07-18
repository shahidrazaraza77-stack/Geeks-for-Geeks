class Solution {
public:
    const int MOD = 1000000007;

    int findWays(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        // 2D Suffix Sum to count 1s in the submatrix from (i, j) to (n-1, m-1)
        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                pre[i][j] = matrix[i][j]
                          + pre[i + 1][j]
                          + pre[i][j + 1]
                          - pre[i + 1][j + 1];
            }
        }

        // dp[i][j] stores the number of ways to cut the submatrix starting at (i, j)
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: 0 cuts remaining (1 piece remaining)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pre[i][j] > 0) {
                    dp[i][j] = 1;
                }
            }
        }

        // Optimization arrays to eliminate the inner loops
        // row_sum[i][j] stores the sum of dp[r][j] for r from i to n-1
        // col_sum[i][j] stores the sum of dp[i][c] for c from j to m-1
        vector<vector<int>> row_sum(n, vector<int>(m, 0));
        vector<vector<int>> col_sum(n, vector<int>(m, 0));

        // Perform k-1 cuts
        for (int cut = 1; cut < k; cut++) {
            // Fill the row_sum and col_sum for the previous DP state
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    row_sum[i][j] = (dp[i][j] + (i + 1 < n ? row_sum[i + 1][j] : 0)) % MOD;
                    col_sum[i][j] = (dp[i][j] + (j + 1 < m ? col_sum[i][j + 1] : 0)) % MOD;
                }
            }

            vector<vector<int>> next_dp(n, vector<int>(m, 0));

            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (pre[i][j] == 0) continue;

                    long long ways = 0;

                    // 1. Optimized Horizontal Cuts
                    // Instead of a loop, look for the first row 'r' where pre[i][j] > pre[r][j]
                    // Since pre[i][j] strictly decreases or stays same as 'r' increases, 
                    // we can find the exact row where the remaining piece has fewer 1s (meaning the cut-off piece contains >= one 1).
                    int next_r = i + 1;
                    while (next_r < n && pre[i][j] == pre[next_r][j]) {
                        next_r++;
                    }
                    if (next_r < n) {
                        ways = (ways + row_sum[next_r][j]) % MOD;
                    }

                    // 2. Optimized Vertical Cuts
                    // Similarly, look for the first column 'c' where pre[i][j] > pre[i][c]
                    int next_c = j + 1;
                    while (next_c < m && pre[i][j] == pre[i][next_c]) {
                        next_c++;
                    }
                    if (next_c < m) {
                        ways = (ways + col_sum[i][next_c]) % MOD;
                    }

                    next_dp[i][j] = ways;
                }
            }
            dp = move(next_dp);
        }

        return dp[0][0];
    }
};