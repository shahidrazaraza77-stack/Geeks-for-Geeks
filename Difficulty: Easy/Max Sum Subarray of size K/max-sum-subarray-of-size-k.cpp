class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {

        int n = arr.size();

        int sum = 0;

        for (int i = 0; i < k; i++)
            sum += arr[i];

        int ans = sum;

        for (int i = k; i < n; i++) {

            sum = sum - arr[i - k] + arr[i];

            ans = max(ans, sum);
        }

        return ans;
    }
};