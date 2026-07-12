class Solution {
  public:
    const int MOD = 1000000007;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int minOperations(vector<int> &b) {
        int n = b.size();
        vector<bool> vis(n, false);
        map<int, int> primeMax;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int cur = i;
                int len = 0;

                while (!vis[cur]) {
                    vis[cur] = true;
                    cur = b[cur] - 1;
                    len++;
                }

                int x = len;
                for (int p = 2; p * p <= x; p++) {
                    if (x % p == 0) {
                        int cnt = 0;
                        while (x % p == 0) {
                            x /= p;
                            cnt++;
                        }
                        primeMax[p] = max(primeMax[p], cnt);
                    }
                }
                if (x > 1)
                    primeMax[x] = max(primeMax[x], 1);
            }
        }

        long long ans = 1;
        for (auto &it : primeMax) {
            ans = (ans * power(it.first, it.second)) % MOD;
        }

        return (int)ans;
    }
};