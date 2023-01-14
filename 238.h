#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> res(nums.size());
        std::vector<int> lpp(nums.size());
        std::vector<int> rpp(nums.size());

        lpp[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            lpp[i] = nums[i - 1] * lpp[i - 1];
        }

        rpp.back() = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            rpp[i] = nums[i + 1] * rpp[i + 1];
        }

        for (int i = 0; i < nums.size(); ++i) {
            res[i] = lpp[i] * rpp[i];
        }

        return res;
    }
};