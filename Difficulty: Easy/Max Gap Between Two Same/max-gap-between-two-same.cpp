class Solution {
public:
    int maxCharGap(string &s) {
        int first[26];
        for (int i = 0; i < 26; i++)
            first[i] = -1;

        int ans = -1;

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';

            if (first[idx] == -1)
                first[idx] = i;
            else
                ans = max(ans, i - first[idx] - 1);
        }

        return ans;
    }
};