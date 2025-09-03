#include <vector>

class Solution {
  public:
    int findDuplicate(std::vector<int> &nums) {
        int res = 0;

        for (int i = 0; i < 32; ++i) {
            int x = 0;
            int y = 0;

            for (int j = 0; j < nums.size(); ++j) {
                x += nums[j] & (1 << i) ? 1 : 0;
                y += j & (1 << i) ? 1 : 0;
            }

            if (x > y) {
                res |= 1 << i;
            }
        }

        return res;
    }
};