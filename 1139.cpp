#include <vector>

class Solution {
  public:
    int largest1BorderedSquare(std::vector<std::vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxBorder = 0;
        std::vector<std::vector<int>> left(m + 1, std::vector<int>(n + 1));
        std::vector<std::vector<int>> up(m + 1, std::vector<int>(n + 1));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (grid[i - 1][j - 1] == 1) {
                    left[i][j] = left[i][j - 1] + 1;
                    up[i][j] = up[i - 1][j] + 1;
                    int border = std::min(left[i][j], up[i][j]);
                    while (left[i - border + 1][j] < border ||
                           up[i][j - border + 1] < border) {
                        border--;
                    }
                    maxBorder = std::max(maxBorder, border);
                }
            }
        }

        return maxBorder * maxBorder;
    }
};