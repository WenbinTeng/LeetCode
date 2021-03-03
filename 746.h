#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        std::vector<int> dp(cost.size() + 1);

        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= cost.size(); ++i)
        {
            dp[i] = std::min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }
        
        return dp.back();
    }
};