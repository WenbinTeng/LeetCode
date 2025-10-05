#include <vector>

class Solution {
  public:
    int coinChange(std::vector<int> &coins, int amount) {
        const int inf = 0x3f3f3f3f;
        std::vector<int> dp(amount + 1, inf);

        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto coin : coins) {
                if (coin <= i) {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == inf ? -1 : dp[amount];
    }
};