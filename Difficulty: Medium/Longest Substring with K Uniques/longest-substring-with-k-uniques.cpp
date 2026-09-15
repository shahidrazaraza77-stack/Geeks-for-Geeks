class Solution {
public:
    int longestKSubstr(string &s, int k) {

        // low = starting index of the window
        // high = ending index of the window
        int low = 0, high = 0;

        // Stores the maximum valid substring length
        int res = INT_MIN;

        // Length of the string
        int n = s.size();

        // Frequency map:
        // key   = character
        // value = frequency of that character in the window
        unordered_map<char, int> f;

        // Expand the window using high
        for (high = 0; high < n; high++) {

            // Add the current character to the window
            f[s[high]]++;

            // If unique characters exceed k,
            // shrink the window from the left
            while (f.size() > k) {

                // Decrease the frequency of the leftmost character
                f[s[low]]--;

                // If its frequency becomes zero,
                // remove it from the map
                if (f[s[low]] == 0) {
                    f.erase(s[low]);
                }

                // Move the left pointer forward
                low++;
            }

            // Update the answer only if there are exactly k
            // unique characters in the current window
            if (f.size() == k) {

                // Current window length
                int len = high - low + 1;

                // Store the maximum length
                res = max(res, len);
            }
        }

        // If no valid substring exists, return -1
        if (res == INT_MIN) {
            return -1;
        }

        return res;
    }
};