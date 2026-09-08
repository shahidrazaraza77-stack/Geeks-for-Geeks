class Solution {
public:
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word) {
        int n = grid.size();
        int m = grid[0].size();

        // 8 directions
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Starting character must match
                if (grid[i][j] != word[0])
                    continue;

                // Try all 8 directions
                for (int d = 0; d < 8; d++) {
                    int r = i;
                    int c = j;
                    bool found = true;

                    for (int k = 1; k < word.size(); k++) {
                        r += dr[d];
                        c += dc[d];

                        // Outside grid
                        if (r < 0 || r >= n || c < 0 || c >= m) {
                            found = false;
                            break;
                        }

                        // Character doesn't match
                        if (grid[r][c] != word[k]) {
                            found = false;
                            break;
                        }
                    }

                    if (found) {
                        ans.push_back({i, j});
                        break; // Don't add same starting cell twice
                    }
                }
            }
        }

        return ans;
    }
};