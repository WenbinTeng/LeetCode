#include <vector>

class Solution {
public:
    int removeElement(std::vector<int> &nums, int val) {
        if (nums.empty())
            return 0;

        int i;
        int j;

        for (i = 0, j = 0; i < nums.size(); nums[j++] = nums[i++]) {
            for (; val == nums[i];)
                if (++i >= nums.size())
                    return j;
        }

        return j;
    }
};