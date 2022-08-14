#include <vector>

class Solution {
public:
    bool validPartition(std::vector<int>& nums) {
        std::vector<bool> dp(nums.size() + 1);

        dp[0] = true;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (dp[i - 1] && nums[i] == nums[i - 1]) dp[i + 1] = true;
            else if (i > 1 && dp[i - 2] && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) dp[i + 1] = true;
            else if (i > 1 && dp[i - 2] && nums[i] - nums[i - 1] == 1 && nums[i - 1] - nums[i - 2] == 1) dp[i + 1] = true;
        }

        return dp.back();
    }
};