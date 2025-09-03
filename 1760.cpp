#include <vector>

class Solution {
  public:
    int minimumSize(std::vector<int> &nums, int maxOperations) {
        int res = 0;
        for (int l = 1, r = 1e+9; l <= r;) {
            int cnt = 0;
            for (const auto &iter : nums) {
                cnt += (iter - 1) / ((l + r) / 2);
            }

            res = cnt <= maxOperations ? (l + r) / 2 : res;

            if (cnt <= maxOperations) {
                r = (l + r) / 2 - 1;
            } else {
                l = (l + r) / 2 + 1;
            }
        }

        return res;
    }
};