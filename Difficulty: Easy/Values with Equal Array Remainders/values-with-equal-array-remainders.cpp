class Solution {
  public:
    int sameMod(vector<int> &arr) {
        int n = arr.size();

        // Calculate GCD of differences
        long long g = 0;
        for (int i = 1; i < n; i++) {
            g = gcd(g, (long long)abs(arr[i] - arr[0]));
        }

        // All elements are equal
        if (g == 0)
            return -1;

        // Count divisors of g
        int ans = 0;
        for (long long i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                ans++;              // i
                if (i != g / i)
                    ans++;          // g/i
            }
        }

        return ans;
    }
};