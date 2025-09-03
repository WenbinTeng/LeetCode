#include <vector>

class Solution {
  public:
    int removeDuplicates(std::vector<int> &nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }

        int left = 2;
        int right = 2;

        while (right < nums.size()) {
            if (nums[right] != nums[left - 1] ||
                nums[right] != nums[left - 2]) {
                nums[left] = nums[right];
                left++;
            }
            right++;
        }

        return left;
    }
};