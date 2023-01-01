#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int> &nums) {
        int l = 0;
        int r = 0;
        while (r < nums.size()) {
            if (l < 2 || nums[l - 2] < nums[r]) {
                nums[l] = nums[r];
                ++l;
            }
            ++r;
        }

        return l;
    }
};