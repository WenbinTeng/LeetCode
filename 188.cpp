#include <vector>

class Solution {
  public:
    int maxProfit(int k, std::vector<int> &prices) {
        if (prices.empty())
            return 0;

        std::vector<std::vector<int>> dp(prices.size(),
                                         std::vector<int>(2 * k + 1, 0));

        for (int i = 1; i < 2 * k; i += 2) {
            dp[0][i] = -prices[0];
            dp[0][i + 1] = 0;
        }

        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 1; j < 2 * k; j += 2) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                dp[i][j + 1] =
                    std::max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
            }
        }

        return dp.back().back();
    }
};