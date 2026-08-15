class Solution {
  public:
    int countWithout(int n, int d) {
        if (n == 0) return 0;

        string s = to_string(n);
        int len = s.size();

        // pow10[i] = 10^i
        long long pow10[11];
        pow10[0] = 1;
        for (int i = 1; i <= 10; i++)
            pow10[i] = pow10[i - 1] * 10;

        // Count valid positive numbers having fewer than len digits
        long long ans = 0;

        for (int l = 1; l < len; l++) {
            // First digit: 1-9, excluding d
            int first = 9 - (d != 0 ? 1 : 0);

            // Remaining digits: 0-9, excluding d
            long long ways = first;
            for (int i = 1; i < l; i++)
                ways *= 10 - 1;

            ans += ways;
        }

        // Count valid numbers having exactly len digits
        for (int i = 0; i < len; i++) {
            int cur = s[i] - '0';

            int smaller;

            if (i == 0) {
                // First digit cannot be 0
                smaller = cur - 1;

                // Remove d if d is a valid smaller first digit
                if (d != 0 && d < cur)
                    smaller--;
            } else {
                smaller = cur;

                // Remove d from digits 0...cur-1
                if (d < cur)
                    smaller--;
            }

            // If current digit is d, we cannot continue
            if (smaller > 0) {
                long long ways = smaller;

                for (int j = i + 1; j < len; j++)
                    ways *= 9;

                ans += ways;
            }

            if (cur == d)
                return ans;
        }

        // Include n itself
        return ans + 1;
    }
};