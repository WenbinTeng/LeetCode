#include <vector>

class Solution {
  public:
    int rob(std::vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0];

        const int n = nums.size();
        std::vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};