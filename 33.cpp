#include <vector>

class Solution {
  public:
    int search(std::vector<int> &nums, int target) {
        return nums.empty() ? -1
                            : binarySearch(nums, 0, nums.size() - 1, target);
    }

  private:
    int binarySearch(std::vector<int> &nums, int l, int r, int target) {
        return l > r ? -1
               : nums[(l + r) / 2] == target
                   ? (l + r) / 2
                   : std::max(binarySearch(nums, l, (l + r) / 2 - 1, target),
                              binarySearch(nums, (l + r) / 2 + 1, r, target));
    }
};