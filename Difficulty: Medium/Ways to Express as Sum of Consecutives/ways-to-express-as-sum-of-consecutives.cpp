class Solution {
public:
    int getCount(int n) {
        int count = 0;
        long long twoN = 2LL * n;

        // Try every possible length of consecutive numbers
        for (long long k = 2; k * (k + 1) / 2 <= n; k++) {

            // k must divide 2*n
            if (twoN % k != 0)
                continue;

            // Check if starting number is a positive integer
            long long t = twoN / k - k + 1;

            if (t > 0 && t % 2 == 0)
                count++;
        }

        return count;
    }
};