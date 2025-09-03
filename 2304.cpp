#include <vector>

class Solution {
  public:
    int minPathCost(std::vector<std::vector<int>> &grid,
                    std::vector<std::vector<int>> &moveCost) {
        const int inf = 0x3f3f3f3f;
        int res = inf;
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> cost(grid);

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int c = inf;

                for (int k = 0; k < grid[0].size(); ++k) {
                    c = std::min(c,
                                 cost[i - 1][k] + moveCost[grid[i - 1][k]][j]);
                }

                cost[i][j] += c;
            }
        }

        for (int i = 0; i < n; ++i) {
            res = std::min(res, cost[m - 1][i]);
        }

        return res;
    }
};