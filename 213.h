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

        std::vector<int> dp1(n);

        dp1[0] = nums[0];
        dp1[1] = nums[1];
        dp1[2] = nums[0] + nums[2];

        for (int i = 3; i < n - 1; ++i) {
            dp1[i] = std::max(dp1[i - 2], dp1[i - 3]) + nums[i];
        }

        std::vector<int> dp2(n);

        dp2[0] = 0;
        dp2[1] = nums[1];
        dp2[2] = nums[2];

        for (int i = 3; i < n; ++i) {
            dp2[i] = std::max(dp2[i - 2], dp2[i - 3]) + nums[i];
        }

        return std::max(std::max(dp1[n - 2], dp1[n - 3]), std::max(dp2[n - 1], dp2[n - 2]));
    }
};