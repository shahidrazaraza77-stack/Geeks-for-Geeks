class Solution {
public:
    int countStrings(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> prev(k + 1, vector<long long>(2, 0));
        vector<vector<long long>> curr(k + 1, vector<long long>(2, 0));

        prev[0][0] = 1; // "0"
        prev[0][1] = 1; // "1"

        for (int len = 2; len <= n; len++) {

            for (int j = 0; j <= k; j++) {
                curr[j][0] = 0;
                curr[j][1] = 0;
            }

            for (int j = 0; j <= k; j++) {

                // Append 0
                curr[j][0] = (prev[j][0] + prev[j][1]) % MOD;

                // Append 1 after 0
                curr[j][1] = (curr[j][1] + prev[j][0]) % MOD;

                // Append 1 after 1
                if (j > 0)
                    curr[j][1] = (curr[j][1] + prev[j - 1][1]) % MOD;
            }

            prev = curr;
        }

        return (prev[k][0] + prev[k][1]) % MOD;
    }
};