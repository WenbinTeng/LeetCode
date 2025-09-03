#include <vector>

class Solution {
  public:
    int minimumSubarrayLength(std::vector<int> &nums, int k) {
        int res = INT_MAX;

        for (int l = 0; l < nums.size(); l++) {
            int orValue = 0;
            for (int r = l; r < nums.size(); r++) {
                orValue |= nums[r];
                if (orValue >= k) {
                    res = std::min(res, r - l + 1);
                    break;
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};