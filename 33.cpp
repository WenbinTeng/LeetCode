#include <vector>

class Solution {
  public:
    int search(std::vector<int> &nums, int target) {
        int last = nums.back();
        int left = -1;
        int right = nums.size() - 1;

        while (left + 1 < right) {
            int mid = (left + right) / 2;
            int x = nums[mid];
            if (target > last && x <= last) {
                right = mid;
            } else if (x > last && target <= last) {
                left = mid;
            } else if (x >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return nums[right] == target ? right : -1;
    }
};