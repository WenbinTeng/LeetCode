#include <vector>

class Solution {
public:
    int minimumMoves(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        const int max = 0x3f3f3f3f;
        std::vector<std::vector<std::array<int, 2>>> f(n, std::vector<std::array<int, 2>>(n, {max, max}));

        f[0][0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                bool hor = (j + 1 < n && grid[i][j] == 0 && grid[i][j + 1] == 0);
                bool ver = (i + 1 < n && grid[i][j] == 0 && grid[i + 1][j] == 0);

                if (i - 1 >= 0 && hor) {
                    f[i][j][0] = std::min(f[i][j][0], f[i - 1][j][0] + 1);
                }
                if (j - 1 >= 0 && hor) {
                    f[i][j][0] = std::min(f[i][j][0], f[i][j - 1][0] + 1);
                }
                if (i - 1 >= 0 && ver) {
                    f[i][j][1] = std::min(f[i][j][1], f[i - 1][j][1] + 1);
                }
                if (j - 1 >= 0 && ver) {
                    f[i][j][1] = std::min(f[i][j][1], f[i][j - 1][1] + 1);
                }

                if (hor && ver && grid[i + 1][j + 1] == 0) {
                    f[i][j][0] = std::min(f[i][j][0], f[i][j][1] + 1);
                    f[i][j][1] = std::min(f[i][j][1], f[i][j][0] + 1);
                }
            }
        }

        return (f[n - 1][n - 2][0] == max ? -1 : f[n - 1][n - 2][0]);
    }
};