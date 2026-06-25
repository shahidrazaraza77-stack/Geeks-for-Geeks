class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int n = arr.size() + 1;
        int ans = 0;
        
        for (int i = 1; i <= n; i++)
            ans ^= i;
            
        for (int num : arr)
            ans ^= num;
            
        return ans;
    }
};