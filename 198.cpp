#include <vector>

class Solution {
  public:
    int rob(std::vector<int> &nums) {
        int n = nums.size();

        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return std::max(nums[0], nums[1]);

        std::vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];

        for (int i = 3; i < n; ++i) {
            dp[i] = std::max(dp[i - 2], dp[i - 3]) + nums[i];
        }

        return std::max(dp[n - 1], dp[n - 2]);
    }
};