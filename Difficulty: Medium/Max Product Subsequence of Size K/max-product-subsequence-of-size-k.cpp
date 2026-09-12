class Solution {
public:
    int maxProduct(vector<int> &arr, int k) {
        int n = arr.size();

        const long long INF = 1e18;

        vector<vector<long long>> maxi(
            n + 1, vector<long long>(k + 1, -INF)
        );

        vector<vector<long long>> mini(
            n + 1, vector<long long>(k + 1, INF)
        );

        maxi[0][0] = 1;
        mini[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            int x = arr[i - 1];

            for (int j = 0; j <= min(i, k); j++) {

                // Case 1: Don't choose current element
                maxi[i][j] = maxi[i - 1][j];
                mini[i][j] = mini[i - 1][j];

                // Case 2: Choose current element
                if (j > 0 && maxi[i - 1][j - 1] != -INF) {
                    long long a = maxi[i - 1][j - 1] * x;
                    long long b = mini[i - 1][j - 1] * x;

                    maxi[i][j] = max({maxi[i][j], a, b});
                    mini[i][j] = min({mini[i][j], a, b});
                }
            }
        }

        return (int)maxi[n][k];
    }
};