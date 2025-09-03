#include <vector>

class Solution {
  public:
    bool check(std::vector<int> &nums) {
        int start = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                start = i;
                break;
            }
        }

        for (int i = start; i != (start - 1 + nums.size()) % nums.size();
             i = (i + 1) % nums.size()) {
            if (nums[i] > nums[(i + 1) % nums.size()])
                return false;
        }

        return true;
    }
};