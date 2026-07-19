class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();

        vector<int> inc(n), dec(n);

        // inc[i] = farthest index reachable by non-decreasing sequence from i
        inc[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1])
                inc[i] = inc[i + 1];
            else
                inc[i] = i;
        }

        // dec[i] = leftmost index reachable by non-increasing sequence ending at i
        dec[0] = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] >= arr[i])
                dec[i] = dec[i - 1];
            else
                dec[i] = i;
        }

        vector<bool> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0], r = q[1];
            int peak = min(inc[l], r);
            ans.push_back(dec[r] <= peak);
        }

        return ans;
    }
};