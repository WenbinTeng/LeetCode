#include <algorithm>
#include <vector>

class Solution {
  public:
    int maximumTop(std::vector<int> &nums, int k) {
        if (k == 0) {
            return nums[0];
        } else if (k == 1) {
            return nums.size() > 1 ? nums[1] : -1;
        } else if (k <= nums.size()) {
            int maxValue = INT_MIN;

            for (int i = 0; i < k - 1; ++i) {
                if (maxValue < nums[i]) {
                    maxValue = nums[i];
                }
            }

            return k == nums.size() ? maxValue : std::max(maxValue, nums[k]);
        } else {
            if (nums.size() > 1) {
                int maxValue = INT_MIN;

                for (int i = 0; i < nums.size(); ++i) {
                    if (maxValue < nums[i]) {
                        maxValue = nums[i];
                    }
                }

                return maxValue;
            } else {
                return k % 2 == 0 ? nums[0] : -1;
            }
        }

        return -1;
    }
};