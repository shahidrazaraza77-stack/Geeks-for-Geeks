class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<int> maxEnd(n);
        maxEnd[0] = arr[0];
        
        // Kadane: maximum subarray sum ending at each index
        for (int i = 1; i < n; i++) {
            maxEnd[i] = max(arr[i], maxEnd[i - 1] + arr[i]);
        }
        
        int windowSum = 0;
        for (int i = 0; i < k; i++)
            windowSum += arr[i];
        
        int ans = windowSum;
        
        for (int i = k; i < n; i++) {
            windowSum += arr[i];
            windowSum -= arr[i - k];
            
            ans = max(ans, windowSum);
            ans = max(ans, windowSum + maxEnd[i - k]);
        }
        
        return ans;
    }
};