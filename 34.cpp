#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<int> searchRange(std::vector<int> &nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        auto lower = std::lower_bound(nums.begin(), nums.end(), target);
        auto upper = std::upper_bound(nums.begin(), nums.end(), target);

        if (lower == nums.end() || (*lower != target)) {
            return {-1, -1};
        }

        return {int(lower - nums.begin()), int(upper - nums.begin()) - 1};
    }
};