#include <algorithm>
#include <vector>

class Solution {
  public:
    int arrayPairSum(std::vector<int> &nums) {
        int res = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2)
            res += nums[i];

        return res;
    }
};