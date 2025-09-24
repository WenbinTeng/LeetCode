#include <vector>

class Solution {
  public:
    std::vector<int> productExceptSelf(std::vector<int> &nums) {
        const int n = nums.size();
        std::vector<int> res(n);
        std::vector<int> lpp(n + 1);
        std::vector<int> rpp(n + 1);

        lpp[0] = 1;
        for (int i = 0; i < n; i++) {
            lpp[i + 1] = lpp[i] * nums[i];
        }

        rpp[0] = 1;
        for (int i = 0; i < n; i++) {
            rpp[i + 1] = rpp[i] * nums[n - 1 - i];
        }

        for (int i = 0; i < n; i++) {
            res[i] = lpp[i] * rpp[n - 1 - i];
        }

        return res;
    }
};