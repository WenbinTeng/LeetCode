#include <vector>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, __INT_MAX__);

        dp[0] = 0;

        for (int i = 1; i <= amount; ++i)
        {
            for (const auto& coin : coins)
            {
                if (i - coin >= 0 && dp[i - coin] != __INT_MAX__)
                {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp.back() == __INT_MAX__ ? -1 : dp.back();
    }
};