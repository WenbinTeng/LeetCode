#include <vector>

class Solution {
  public:
    int minSubArrayLen(int target, std::vector<int> &nums) {
        int res = nums.size() + 1;
        int left = 0;
        int right = 0;
        int sum = 0;

        while (right <= nums.size()) {
            if (sum < target) {
                if (right < nums.size()) {
                    sum += nums[right];
                    right++;
                } else
                    break;
            } else {
                res = std::min(res, right - left);
                sum -= nums[left];
                left++;
            }
        }

        return res > nums.size() ? 0 : res;
    }
};