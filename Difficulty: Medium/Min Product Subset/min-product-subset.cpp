class Solution {
public:
    int minProd(vector<int>& arr) {
        int n = arr.size();
        
        int neg = 0, zero = 0;
        int prod = 1;
        int maxNeg = -11;
        
        for (int x : arr) {
            if (x < 0) {
                neg++;
                maxNeg = max(maxNeg, x);
            }
            else if (x == 0) {
                zero++;
            }
            else {
                prod *= x;
            }
        }
        
        // No negative number
        if (neg == 0) {
            if (zero > 0)
                return 0;
            
            int mn = arr[0];
            for (int x : arr)
                mn = min(mn, x);
            
            return mn;
        }
        
        // Odd number of negative elements
        if (neg % 2 == 1) {
            for (int x : arr) {
                if (x < 0)
                    prod *= x;
            }
        }
        else {
            // Even number of negative elements:
            // remove the negative closest to zero
            bool removed = false;
            
            for (int x : arr) {
                if (x < 0) {
                    if (x == maxNeg && !removed) {
                        removed = true;
                    } else {
                        prod *= x;
                    }
                }
            }
        }
        
        return prod;
    }
};