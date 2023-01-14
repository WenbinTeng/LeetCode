#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int l = 0;
        int r = 0;

        while (r < nums.size()) {
            if (nums[r] != 0) {
                std::swap(nums[l], nums[r]);
                ++l;
            }
            ++r;
        }
    }
};