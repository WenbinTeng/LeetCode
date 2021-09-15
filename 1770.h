#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumScore(std::vector<int>& nums, std::vector<int>& multipliers) {
        std::vector<std::vector<int>> dp(1001, std::vector<int>(1001, 0));
        int res = -INT_MAX - 1;
        int n = nums.size();
        int m = multipliers.size();
        for (int k = 1; k <= m; ++k)
        {
            for (int i = 0; i <= k; ++i)
            {
                if (i != 0 && i != k) dp[i][k - i] = std::max(dp[i][k - i - 1] + nums[n - k + i] * multipliers[k - 1], dp[i - 1][k - i] + nums[i - 1] * multipliers[k - 1]);
                else if (i == 0) dp[i][k - i] = dp[i][k - i - 1] + nums[n - k + i] * multipliers[k - 1];
                else if (i == k) dp[i][k - i] = dp[i - 1][k - i] + nums[i - 1    ] * multipliers[k - 1];

                if (k == m) res = std::max(res, dp[i][k - i]);
            }
        }

        return res;
    }
};