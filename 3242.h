#include <vector>
#include <unordered_map>

class NeighborSum {
public:
    NeighborSum(std::vector<std::vector<int>>& grid) : m(grid.size()), n(grid[0].size()), myGrid(grid) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                posDict[grid[i][j]] = std::make_pair(i, j);
            }
        }
    }
    
    int adjacentSum(int value) {
        auto [i, j] = posDict[value];
        int sum = 0;
        if (i - 1 >= 0)
            sum += myGrid[i - 1][j];
        if (j - 1 >= 0)
            sum += myGrid[i][j - 1];
        if (i + 1 <  m)
            sum += myGrid[i + 1][j];
        if (j + 1 <  n)
            sum += myGrid[i][j + 1];
        return sum;
    }
    
    int diagonalSum(int value) {
        auto [i, j] = posDict[value];
        int sum = 0;
        if (i - 1 >= 0 && j - 1 >= 0)
            sum += myGrid[i - 1][j - 1];
        if (i + 1 <  m && j - 1 >= 0)
            sum += myGrid[i + 1][j - 1];
        if (i - 1 >= 0 && j + 1 <  n)
            sum += myGrid[i - 1][j + 1];
        if (i + 1 <  m && j + 1 < n)
            sum += myGrid[i + 1][j + 1];
        return sum;
    }

private:
    int m;
    int n;
    std::vector<std::vector<int>>& myGrid;
    std::unordered_map<int, std::pair<int, int>> posDict;
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */