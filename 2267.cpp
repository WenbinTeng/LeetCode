#include <vector>

class Solution {
  public:
    bool hasValidPath(std::vector<std::vector<char>> &grid) {
        if (grid[0][0] == ')')
            return false;

        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<std::vector<bool>>> dp(
            m, std::vector<std::vector<bool>>(n, std::vector<bool>(n + m)));
        dp[0][0][1] = true;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i || j) {
                    for (int k = 0; k < n + m; ++k) {
                        int t = k - (grid[i][j] == '(' ? 1 : -1);

                        if (t < 0 || t >= n + m)
                            continue;
                        if (i)
                            dp[i][j][k] = dp[i][j][k] || dp[i - 1][j][t];
                        if (j)
                            dp[i][j][k] = dp[i][j][k] || dp[i][j - 1][t];
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};