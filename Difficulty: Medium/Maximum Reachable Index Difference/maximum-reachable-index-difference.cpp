class Solution {
  public:
    int maxIndexDifference(string &s) {
        int n = s.size();

        vector<int> dp(n);
        vector<int> best(26, -1);

        int ans = -1;

        for (int i = n - 1; i >= 0; i--) {
            int cur = s[i] - 'a';

            // If current character is 'z', no further jump is possible
            if (cur == 25) {
                dp[i] = i;
            }
            else {
                if (best[cur + 1] != -1)
                    dp[i] = best[cur + 1];
                else
                    dp[i] = i;
            }

            // Update the best reachable index for this character
            best[cur] = max(best[cur], dp[i]);

            // Update answer if current character is 'a'
            if (s[i] == 'a') {
                ans = max(ans, dp[i] - i);
            }
        }

        return ans;
    }
};