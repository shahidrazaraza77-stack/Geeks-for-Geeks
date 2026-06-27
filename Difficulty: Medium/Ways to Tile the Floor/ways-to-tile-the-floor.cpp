const int MOD = 1e9 + 7;

class Solution {
  public:
    int countWays(int n, int m) {
        // dp[i] = number of ways to tile floor of size i × m
        std::vector<int> dp(n+1, 0);

        // Base cases
        for (int i = 0; i < m && i <= n; i++) {
            dp[i] = 1;
        }
        if (n >= m) dp[m] = 2;

        // Recurrence relation
        for (int i = m+1; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-m]) % MOD;
        }

        return dp[n];
    }
};
