#include <vector>

class Solution {
  public:
    bool kLengthApart(std::vector<int> &nums, int k) {
        int prevPos = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                prevPos = i;
                break;
            }
        }

        for (int i = prevPos + 1; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (i - prevPos - 1 < k) {
                    return false;
                }
                prevPos = i;
            }
        }

        return true;
    }
};