class Solution {
  public:
    int gcd(int a, int b) {
        while (b) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    int pairCount(int x, int y) {
        // LCM must be divisible by GCD
        if (y % x != 0) return 0;

        int k = y / x;
        int ans = 0;

        // Check all divisor pairs (p, q) of k
        for (int p = 1; p * p <= k; p++) {
            if (k % p == 0) {
                int q = k / p;

                // p and q must be coprime
                if (gcd(p, q) == 1) {
                    if (p == q) ans += 1;   // (a, a) counted once
                    else ans += 2;          // (a, b) and (b, a)
                }
            }
        }
        return ans;
    }
};
