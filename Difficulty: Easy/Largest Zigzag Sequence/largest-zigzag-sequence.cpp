class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<int> dp(n);

        // First row
        for (int j = 0; j < n; j++) {
            dp[j] = mat[0][j];
        }

        // Process remaining rows
        for (int i = 1; i < n; i++) {
            
            // Find largest and second largest dp values
            int maxi1 = -1, maxi2 = -1;
            int idx = -1;

            for (int j = 0; j < n; j++) {
                if (dp[j] > maxi1) {
                    maxi2 = maxi1;
                    maxi1 = dp[j];
                    idx = j;
                } 
                else if (dp[j] > maxi2) {
                    maxi2 = dp[j];
                }
            }

            vector<int> newDp(n);

            for (int j = 0; j < n; j++) {
                // Cannot choose same column
                if (j != idx)
                    newDp[j] = mat[i][j] + maxi1;
                else
                    newDp[j] = mat[i][j] + maxi2;
            }

            dp = newDp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};