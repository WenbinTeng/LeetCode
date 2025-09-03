#include <vector>

class Solution {
  public:
    int unequalTriplets(std::vector<int> &nums) {
        int res = 0;

        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                for (int k = j + 1; k < nums.size(); ++k)
                    if (nums[i] != nums[j] && nums[i] != nums[k] &&
                        nums[j] != nums[k])
                        ++res;

        return res;
    }
};