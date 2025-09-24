#include <algorithm>
#include <vector>

class Solution {
  public:
    int maxSubArray(std::vector<int> &nums) {
        const int n = nums.size();
        std::vector<int> dp(n);

        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};