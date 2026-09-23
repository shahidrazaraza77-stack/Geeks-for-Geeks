class Solution {
  public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();

        vector<long long> left(n), right(n);

        // Maximum possible height at i
        // when building from the left.
        left[0] = min(1LL, (long long)arr[0]);

        for (int i = 1; i < n; i++) {
            left[i] = min((long long)arr[i], left[i - 1] + 1);
        }

        // Maximum possible height at i
        // when building from the right.
        right[n - 1] = min(1LL, (long long)arr[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            right[i] = min((long long)arr[i], right[i + 1] + 1);
        }

        long long total = 0;
        long long best = 0;

        for (int x : arr) {
            total += x;
        }

        // Choose every position as the peak.
        for (int i = 0; i < n; i++) {
            long long height = min(left[i], right[i]);

            // A pyramid of height h has total height-sum h^2.
            best = max(best, height * height);
        }

        return (int)(total - best);
    }
};