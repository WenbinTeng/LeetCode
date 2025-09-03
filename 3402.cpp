#include <vector>

class Solution {
  public:
    int minimumOperations(std::vector<std::vector<int>> &grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                if (grid[i][j] <= grid[i - 1][j]) {
                    res += (grid[i - 1][j] + 1 - grid[i][j]);
                    grid[i][j] = grid[i - 1][j] + 1;
                }
            }
        }

        return res;
    }
};