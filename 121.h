#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = std::max(dp[i - 1][1], -prices[i]);
        }

        return dp[prices.size() - 1][0];
    }
};