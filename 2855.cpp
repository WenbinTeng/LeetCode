#include <vector>

class Solution {
  public:
    int minimumRightShifts(std::vector<int> &nums) {
        int n = nums.size();
        int start = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                start = i;
                break;
            }
        }

        return checkGreater(nums, start) ? (n - start) % n : -1;
    }

  private:
    bool checkGreater(std::vector<int> &nums, int start) {
        for (int i = 0, n = nums.size(); i < n - 1; i++) {
            if (nums[(start + i) % n] > nums[(start + i + 1) % n]) {
                return false;
            }
        }
        return true;
    }
};