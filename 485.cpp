#include <vector>

class Solution {
  public:
    int findMaxConsecutiveOnes(std::vector<int> &nums) {
        int res = 0;
        for (int i = 0, j = 0; i < nums.size(); i = ++j) {
            while (j < nums.size() && nums[j] == 1)
                ++j;
            res = std::max(res, j - i);
        }

        return res;
    }
};