#include <vector>

class Solution {
public:
    int projectionArea(std::vector<std::vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int areaXY = 0;
        int areaXZ = 0;
        int areaYZ = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    areaXY++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int maxH = 0;
            for (int j = 0; j < n; j++) {
                maxH = std::max(maxH, grid[i][j]);
            }
            areaXZ += maxH;
        }

        for (int j = 0; j < n; j++) {
            int maxH = 0;
            for (int i = 0; i < m; i++) {
                maxH = std::max(maxH, grid[i][j]);
            }
            areaYZ += maxH;
        }

        return areaXY + areaXZ + areaYZ;
    }
};