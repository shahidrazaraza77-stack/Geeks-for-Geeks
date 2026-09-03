class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();

        if (n <= 1)
            return 0;

        long long keep = 0;
        long long replace = 0;

        for (int i = 1; i < n; i++) {

            // Keep arr[i] unchanged
            long long newKeep = max(
                keep + abs(arr[i] - arr[i - 1]),
                replace + abs(arr[i] - 1)
            );

            // Replace arr[i] with 1
            long long newReplace = max(
                keep + abs(1 - arr[i - 1]),
                replace
            );

            keep = newKeep;
            replace = newReplace;
        }

        return (int)max(keep, replace);
    }
};