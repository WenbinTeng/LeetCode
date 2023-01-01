#include <vector>

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>> &matrix) {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        if (m * n == 0)
            return 0;

        std::vector<std::vector<int>> dp(m, std::vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] == '0' ? 0 : 1;
                } else if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else if (matrix[i][j] == '1') {
                    dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }

                res = std::max(res, dp[i][j]);
            }
        }

        return res * res;
    }
};