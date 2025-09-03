#include <vector>

class Solution {
  public:
    int maxSubarrays(std::vector<int> &nums) {
        int res = 0;
        int andVal = 0xffffffff;

        for (auto num : nums) {
            andVal &= num;
            if (andVal == 0) {
                andVal = 0xffffffff;
                res++;
            }
        }

        return std::max(res, 1);
    }
};