#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>> &grid) {
        std::vector<std::vector<int>> res(grid.size() - 2, std::vector<int>(grid.size() - 2));

        for (int i = 0; i < grid.size() - 2; ++i) {
            for (int j = 0; j < grid.size() - 2; ++j) {
                std::vector<int> t = {grid[i][j], grid[i][j + 1], grid[i][j + 2], grid[i + 1][j], grid[i + 1][j + 1], grid[i + 1][j + 2], grid[i + 2][j], grid[i + 2][j + 1], grid[i + 2][j + 2]};
                res[i][j] = *std::max_element(t.begin(), t.end());
            }
        }

        return res;
    }
};