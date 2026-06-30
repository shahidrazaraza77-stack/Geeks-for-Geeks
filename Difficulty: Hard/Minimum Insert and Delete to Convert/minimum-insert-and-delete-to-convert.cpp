class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // Map elements of b to their index
        unordered_map<int, int> mp;
        
        for(int i = 0; i < b.size(); i++) {
            mp[b[i]] = i;
        }
        
        vector<int> arr;
        
        // Convert common elements of a into indices of b
        for(int x : a) {
            if(mp.find(x) != mp.end()) {
                arr.push_back(mp[x]);
            }
        }
        
        // Find LIS length
        vector<int> lis;
        
        for(int x : arr) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            
            if(it == lis.end())
                lis.push_back(x);
            else
                *it = x;
        }
        
        int lcs = lis.size();
        
        return (a.size() - lcs) + (b.size() - lcs);
    }
};