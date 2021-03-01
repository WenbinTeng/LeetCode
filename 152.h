#include <vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        std::vector<int> dp   (nums.size());
        std::vector<int> dpMin(nums.size());
        std::vector<int> dpMax(nums.size());

        dp   [0] = nums[0];
        dpMin[0] = nums[0];
        dpMax[0] = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            dpMin[i] = std::min(nums[i], std::min(dpMin[i - 1] * nums[i], dpMax[i - 1] * nums[i]));
            dpMax[i] = std::max(nums[i], std::max(dpMin[i - 1] * nums[i], dpMax[i - 1] * nums[i]));
            dp   [i] = std::max(dp[i - 1], dpMax[i]);
        }

        return dp.back();
    }
};