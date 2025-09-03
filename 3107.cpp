#include <algorithm>
#include <vector>

class Solution {
  public:
    long long minOperationsToMakeMedianK(std::vector<int> &nums, int k) {
        int half = nums.size() / 2;
        long long res = 0;

        std::sort(nums.begin(), nums.end());

        if (nums[half] > k) {
            for (int i = half; i >= 0 && nums[i] > k; i--) {
                res += nums[i] - k;
            }
        } else {
            for (int i = half; i < nums.size() && nums[i] < k; i++) {
                res += k - nums[i];
            }
        }

        return res;
    }
};