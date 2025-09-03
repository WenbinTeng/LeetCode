#include <algorithm>
#include <vector>

class Solution {
  public:
    int minOperations(std::vector<std::vector<int>> &grid, int x) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        std::vector<int> temp;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (std::abs(grid[i][j] - grid[0][0]) % x != 0)
                    return -1;
            }

            temp.insert(temp.end(), grid[i].begin(), grid[i].end());
        }

        std::sort(temp.begin(), temp.end());

        for (int i = 0, midVal = temp[temp.size() / 2]; i < temp.size(); ++i) {
            res += std::abs(temp[i] - midVal) / x;
        }

        return res;
    }
};