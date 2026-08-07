class Solution {
  public:
    long long countFriendsPairings(int n) {
        // Base cases
        if (n <= 2) return n;

        // DP array
        long long dp[n+1];
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + (i-1) * dp[i-2];
        }

        return dp[n];
    }
};
