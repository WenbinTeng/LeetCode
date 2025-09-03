#include <vector>

class Solution {
  public:
    bool canJump(std::vector<int> &nums) {
        int furthest = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i <= furthest) {
                furthest = std::max(furthest, i + nums[i]);
                if (furthest >= nums.size() - 1) {
                    return true;
                }
            }
        }

        return false;
    }
};