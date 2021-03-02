#include <vector>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        int res = 1;
        int len = 1;

        std::sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] - nums[i - 1] == 1)
            {
                len += 1;
                continue;
            }
            if (nums[i] - nums[i - 1] != 0)
            {
                res = std::max(res, len);
                len =  1;
                continue;
            }
        }

        return std::max(res, len);
    }
};