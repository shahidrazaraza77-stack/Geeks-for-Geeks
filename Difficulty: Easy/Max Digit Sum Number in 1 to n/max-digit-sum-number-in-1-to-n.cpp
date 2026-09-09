class Solution {
  public:
    int digitSum(long long x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int findMax(int n) {
        string s = to_string(n);
        int bestNum = n;
        int bestSum = digitSum(n);

        // Try reducing each digit (except leading zero case)
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') continue; // can't reduce 0
            string candidate = s;
            candidate[i] = (char)(s[i] - 1);
            for (int j = i + 1; j < s.size(); j++) candidate[j] = '9';

            long long candNum = stoll(candidate);
            if (candNum <= n) { // must be within range
                int candSum = digitSum(candNum);
                if (candSum > bestSum || (candSum == bestSum && candNum > bestNum)) {
                    bestSum = candSum;
                    bestNum = candNum;
                }
            }
        }
        return bestNum;
    }
};
