#include <algorithm>
#include <vector>

class Solution {
  public:
    int findLengthOfLCIS(std::vector<int> &nums) {
        if (nums.empty())
            return 0;

        std::vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                dp[i] = dp[i - 1] + 1;
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};