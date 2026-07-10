class Solution {
public:
    int countTriplets(int target, vector<int>& arr) {

        sort(arr.begin(), arr.end());

        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = arr[i] + arr[left] + arr[right];

                if (sum < target) {
                    ans += (right - left);
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return ans;
    }
};