class Solution {
    bool findPath(Node* root, int val, vector<int>& path) {
        if (root == nullptr)
            return false;

        if (root->data == val)
            return true;

        // 0 = left, 1 = right
        path.push_back(0);
        if (findPath(root->left, val, path))
            return true;
        path.pop_back();

        path.push_back(1);
        if (findPath(root->right, val, path))
            return true;
        path.pop_back();

        return false;
    }

  public:
    int numberOfTurns(Node* root, int p, int q) {
        vector<int> pathP, pathQ;

        if (!findPath(root, p, pathP) || !findPath(root, q, pathQ))
            return -1;

        // Find common path up to LCA
        int i = 0;
        while (i < pathP.size() && i < pathQ.size() &&
               pathP[i] == pathQ[i]) {
            i++;
        }

        // Same node
        if (i == pathP.size() && i == pathQ.size())
            return -1;

        // Build complete path directions:
        // p -> LCA: reverse(pathP)
        // LCA -> q: pathQ
        vector<int> directions;

        for (int j = pathP.size() - 1; j >= i; j--)
            directions.push_back(pathP[j]);

        for (int j = i; j < pathQ.size(); j++)
            directions.push_back(pathQ[j]);

        // A turn occurs when direction changes
        int turns = 0;

        for (int j = 1; j < directions.size(); j++) {
            if (directions[j] != directions[j - 1])
                turns++;
        }

        return turns == 0 ? -1 : turns;
    }
};