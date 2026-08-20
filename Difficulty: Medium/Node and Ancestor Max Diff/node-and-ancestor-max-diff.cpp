class Solution {
  public:
    int maxDiff(Node* root) {
        if (root == nullptr)
            return 0;

        int ans = INT_MIN;

        // Find minimum value in the subtree and calculate
        // ancestor - descendant difference.
        function<int(Node*)> solve = [&](Node* node) {
            if (node == nullptr)
                return INT_MAX;

            int leftMin = solve(node->left);
            int rightMin = solve(node->right);

            int minDescendant = min(leftMin, rightMin);

            if (minDescendant != INT_MAX)
                ans = max(ans, node->data - minDescendant);

            return min(node->data, minDescendant);
        };

        solve(root);
        return ans;
    }
};