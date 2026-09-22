class Solution {
  public:
    string findLongestWord(string &s, vector<string> &d) {
        int n = s.size();

        // Store positions of each character in s
        vector<int> pos[26];

        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'].push_back(i);
        }

        string ans = "";

        for (string &word : d) {
            int prev = -1;
            bool possible = true;

            for (char c : word) {
                vector<int> &v = pos[c - 'a'];

                // Find first occurrence of c after prev
                auto it = upper_bound(v.begin(), v.end(), prev);

                if (it == v.end()) {
                    possible = false;
                    break;
                }

                prev = *it;
            }

            if (possible) {
                if (word.size() > ans.size() ||
                    (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};