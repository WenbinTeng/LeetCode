#include <vector>

class Solution {
  public:
    long long sellingWood(int m, int n, std::vector<std::vector<int>> &prices) {
        std::vector<std::vector<int>> profit(m + 1, std::vector<int>(n + 1, 0));
        std::vector<std::vector<long long>> dp(
            m + 1, std::vector<long long>(n + 1, 0));

        for (const auto &price : prices) {
            profit[price[0]][price[1]] = price[2];
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = profit[i][j];

                for (int k = 1; k < i; ++k) {
                    dp[i][j] = std::max(dp[i][j], dp[k][j] + dp[i - k][j]);
                }

                for (int k = 1; k < j; ++k) {
                    dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[i][j - k]);
                }
            }
        }

        return dp.back().back();
    }
};