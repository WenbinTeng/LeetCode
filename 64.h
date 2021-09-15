#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        mem = std::vector<std::vector<int>>(grid.size(), std::vector<int>(grid[0].size(), -1));
        return dfs(grid, 0, 0);
    }

private:
    std::vector<std::vector<int>> mem;

    int dfs(std::vector<std::vector<int>>& grid, int rowIndex, int colIndex)
    {
        if (rowIndex >= grid.size() || colIndex >= grid[0].size()) return INT_MAX;

        if (rowIndex == grid.size() - 1 && colIndex == grid[0].size() - 1) return grid[rowIndex][colIndex];

        if (mem[rowIndex][colIndex] >= 0) return mem[rowIndex][colIndex];

        return mem[rowIndex][colIndex] = std::min(dfs(grid, rowIndex + 1, colIndex), dfs(grid, rowIndex, colIndex + 1)) + grid[rowIndex][colIndex];
    }
};