#include <vector>
#include <algorithm>

class Solution {
public:
    int deleteAndEarn(std::vector<int>& nums) {
        int max = *std::max_element(nums.begin(), nums.end());
        std::vector<int> sums(10001, 0);
        std::vector<std::vector<int>> dp(max + 1, std::vector<int>(2));

        for (const auto& num : nums)
        {
            ++sums[num];
        }

        for (int i = 1; i <= max; ++i)
        {
            dp[i][1] = dp[i - 1][0] + i * sums[i];
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
        }

        return std::max(dp[max][0], dp[max][1]);
    }
};