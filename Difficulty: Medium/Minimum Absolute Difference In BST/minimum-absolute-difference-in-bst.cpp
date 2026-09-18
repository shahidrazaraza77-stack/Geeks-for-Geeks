class Solution {
  public:
    int absDiff(Node *root) {
        int ans = INT_MAX;
        Node* prev = nullptr;

        // Iterative inorder traversal
        stack<Node*> st;
        Node* curr = root;

        while (curr != nullptr || !st.empty()) {
            // Go to the leftmost node
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            // Compare with previous inorder value
            if (prev != nullptr) {
                ans = min(ans, curr->data - prev->data);
            }

            prev = curr;
            curr = curr->right;
        }

        return ans;
    }
};