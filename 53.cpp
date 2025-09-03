#include <vector>

class Solution {
  public:
    int maxSubArray(std::vector<int> &nums) {
        int res = nums[0];
        int pre = 0;

        for (const auto &iter : nums) {
            pre = std::max(pre + iter, iter);
            res = std::max(res, pre);
        }

        return res;
    }
};