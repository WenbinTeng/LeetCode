#include <vector>

class Solution {
  public:
    std::vector<int> buildArray(std::vector<int> &nums) {
        std::vector<int> res(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            res[i] = nums[nums[i]];
        }

        return res;
    }
};