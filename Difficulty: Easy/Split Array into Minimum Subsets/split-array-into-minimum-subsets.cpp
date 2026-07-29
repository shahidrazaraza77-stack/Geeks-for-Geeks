class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        // Step 2: At least one subset
        int count = 1;
        
        // Step 3: Traverse and count gaps
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i-1] > 1) {
                count++;
            }
        }
        
        return count;
    }
};
