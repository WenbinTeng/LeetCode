#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxPos = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i <= maxPos)
            {
                maxPos = std::max(maxPos, i + nums[i]);
            }
            if (maxPos >= nums.size() - 1)
            {
                return true;
            }
        }

        return false;
    }
};