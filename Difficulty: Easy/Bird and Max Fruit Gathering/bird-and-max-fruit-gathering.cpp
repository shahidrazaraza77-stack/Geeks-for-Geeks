class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();

        // If we can visit all trees
        if (m == n) {
            long long total = 0;
            for (int x : arr)
                total += x;
            return total;
        }

        // Sum of first m trees
        long long sum = 0;
        for (int i = 0; i < m; i++) {
            sum += arr[i];
        }

        long long ans = sum;

        // Sliding window around the circle
        for (int i = m; i < n + m - 1; i++) {
            sum += arr[i % n];
            sum -= arr[(i - m) % n];

            ans = max(ans, sum);
        }

        return ans;
    }
};