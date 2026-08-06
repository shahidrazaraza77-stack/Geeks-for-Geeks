class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        int ans = 0;
        
        while (true) {
            bool allZero = true;
            
            // Remove all odd values (reverse of increment)
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] & 1) {
                    arr[i]--;
                    ans++;
                }
                if (arr[i] != 0)
                    allZero = false;
            }
            
            if (allZero)
                break;
            
            // Reverse of doubling
            for (int i = 0; i < arr.size(); i++)
                arr[i] /= 2;
            
            ans++;
        }
        
        return ans;
    }
};