#include <vector>

class Solution {
  public:
    int countElements(std::vector<int> &nums) {
        if (nums.size() <= 2)
            return 0;

        int res = 0;
        int minVal = nums[0];
        int maxVal = nums[0];

        for (int i = 0; i < nums.size(); ++i) {
            minVal = std::min(minVal, nums[i]);
            maxVal = std::max(maxVal, nums[i]);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != minVal && nums[i] != maxVal)
                ++res;
        }

        return res;
    }
};