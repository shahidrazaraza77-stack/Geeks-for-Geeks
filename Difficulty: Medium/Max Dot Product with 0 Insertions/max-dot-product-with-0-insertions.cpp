class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        vector<int> prev(m + 1, INT_MIN), cur(m + 1, INT_MIN);

        prev[0] = 0;

        for (int i = 1; i <= n; i++) {
            cur[0] = 0;

            for (int j = 1; j <= m; j++) {
                if (j > i) {
                    cur[j] = INT_MIN;
                    continue;
                }

                cur[j] = max(prev[j],
                             prev[j - 1] + a[i - 1] * b[j - 1]);
            }

            prev = cur;
        }

        return prev[m];
    }
};
