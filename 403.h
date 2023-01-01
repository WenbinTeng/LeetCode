#include <vector>

class Solution {
public:
    bool canCross(std::vector<int> &stones) {
        std::vector<std::vector<bool>> dp(stones.size(), std::vector<bool>(stones.size(), false));
        dp[0][0] = true;

        for (int i = 1; i < stones.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int dist = stones[i] - stones[j];
                if (dist <= j + 1) {
                    dp[i][dist] = dp[j][dist - 1] || dp[j][dist] || dp[j][dist + 1];
                }
            }
        }

        for (int i = 0; i < stones.size(); ++i) {
            if (dp.back()[i])
                return true;
        }

        return false;
    }
};