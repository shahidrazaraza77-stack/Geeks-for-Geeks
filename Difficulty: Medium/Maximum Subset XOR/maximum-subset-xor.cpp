class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        int n = arr.size();
        int index = 0;

        // Build XOR basis
        for (int bit = 31; bit >= 0; bit--) {
            int pivot = -1;
            for (int i = index; i < n; i++) {
                if (arr[i] & (1 << bit)) {
                    pivot = i;
                    break;
                }
            }

            if (pivot == -1) continue;

            swap(arr[index], arr[pivot]);

            for (int i = 0; i < n; i++) {
                if (i != index && (arr[i] & (1 << bit))) {
                    arr[i] ^= arr[index];
                }
            }

            index++;
        }

        int ans = 0;
        for (int i = 0; i < index; i++) {
            ans = max(ans, ans ^ arr[i]);
        }

        return ans;
    }
};