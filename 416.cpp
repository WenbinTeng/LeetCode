#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
  public:
    bool canPartition(std::vector<int> &nums) {
        const int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int max = *std::max_element(nums.begin(), nums.end());
        int target = sum / 2;
        std::vector<std::vector<int>> dp(n, std::vector<int>(target + 1, 0));

        if (n < 2)
            return false;
        if (sum % 2 == 1)
            return false;
        if (max > target)
            return false;

        dp[0][nums[0]] = 1;
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i]) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n - 1][target];
    }
};