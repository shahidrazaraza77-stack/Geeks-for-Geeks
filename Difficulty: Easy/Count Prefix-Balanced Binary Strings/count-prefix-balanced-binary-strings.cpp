class Solution {
public:
    int prefixStrings(int n) {
        const long long MOD = 1000000007;

        long long fact[2001];
        fact[0] = 1;

        for (int i = 1; i <= 2 * n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        auto power = [&](long long a, long long b) {
            long long res = 1;
            while (b) {
                if (b & 1)
                    res = res * a % MOD;
                a = a * a % MOD;
                b >>= 1;
            }
            return res;
        };

        long long numerator = fact[2 * n];
        long long denominator = fact[n] * fact[n] % MOD;
        denominator = denominator * (n + 1) % MOD;

        long long ans = numerator * power(denominator, MOD - 2) % MOD;

        return (int)ans;
    }
};