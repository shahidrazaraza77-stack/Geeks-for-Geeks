class Solution {
  public:
    int countSubsequences(string s, int n) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n, 0);

        for (char c : s) {
            int digit = c - '0';
            vector<long long> ndp = dp;

            // Start a new subsequence with this digit
            ndp[digit % n] = (ndp[digit % n] + 1) % MOD;

            // Add current digit to existing subsequences
            for (int r = 0; r < n; r++) {
                int nr = (r * 10 + digit) % n;
                ndp[nr] = (ndp[nr] + dp[r]) % MOD;
            }

            dp = ndp;
        }

        return dp[0];
    }
};