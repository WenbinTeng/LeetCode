#include <vector>

class Solution {
  public:
    int projectionArea(std::vector<std::vector<int>> &grid) {
        int xyArea = 0;
        int yzArea = 0;
        int zxArea = 0;

        for (int i = 0; i < grid.size(); i++) {
            int yzHeight = 0;
            int zxHeight = 0;

            for (int j = 0; j < grid.size(); j++) {
                xyArea += grid[i][j] > 0 ? 1 : 0;
                yzHeight = std::max(yzHeight, grid[j][i]);
                zxHeight = std::max(zxHeight, grid[i][j]);
            }

            yzArea += yzHeight;
            zxArea += zxHeight;
        }

        return xyArea + yzArea + zxArea;
    }
};