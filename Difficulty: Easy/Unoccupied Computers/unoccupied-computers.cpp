class Solution {
public:
    int solve(int n, string s) {
        vector<bool> inside(26, false);
        vector<bool> rejected(26, false);

        int available = n;
        int ans = 0;

        for (char ch : s) {
            int id = ch - 'A';

            // First occurrence = arrival
            if (!inside[id] && !rejected[id]) {
                if (available > 0) {
                    inside[id] = true;
                    available--;
                } else {
                    rejected[id] = true;
                    ans++;
                }
            }
            // Second occurrence = departure
            else if (inside[id]) {
                inside[id] = false;
                available++;
            }
        }

        return ans;
    }
};