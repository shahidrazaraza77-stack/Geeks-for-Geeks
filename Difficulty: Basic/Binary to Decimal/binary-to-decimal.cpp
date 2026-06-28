class Solution {
public:
    int binaryToDecimal(string &b) {

        int ans = 0;
        int n = b.length();

        for (int i = 0; i < n; i++) {
            if (b[n - 1 - i] == '1') {
                ans += (1 << i);
            }
        }

        return ans;
    }
};