class Solution {
public:
    // Function to count subarrays having sum <= target
    long long countLessEqual(vector<int>& arr, long long target) {
        if (target < 0) return 0;

        long long ans = 0, sum = 0;
        int left = 0;

        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }

    int countSubarray(vector<int>& arr, int l, int r) {
        return countLessEqual(arr, r) - countLessEqual(arr, l - 1);
    }
};