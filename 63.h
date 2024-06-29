#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
        if (obstacleGrid[0][0])
            return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        std::vector<std::vector<int>> rec(m, std::vector<int>(n, 0));

        rec[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    continue;
                if (i > 0)
                    rec[i][j] += rec[i - 1][j];
                if (j > 0)
                    rec[i][j] += rec[i][j - 1];
            }
        }

        return rec[m - 1][n - 1];
    }
};