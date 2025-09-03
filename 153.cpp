#include <vector>

class Solution {
  public:
    int findMin(std::vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = (l + r) / 2;

            if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return nums[l];
    }
};