class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        

 
        int n = arr.size();

        int sum = 0;

             // First window
        for (int i = 0; i < k; i++) {
                 sum += arr[i];
        }

         int maxi = sum;

             // Slide the window
        for (int i = k; i < n; i++) {
            sum += arr[i];       // Add new element
            sum -= arr[i - k];   // Remove old element

            maxi = max(maxi, sum);
        }

        return maxi;
         
     
    }
};