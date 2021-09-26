#include <vector>

class Solution {
public:
    int maximumDifference(std::vector<int>& nums) {
        int res = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] < nums[j])
                {
                    res = std::max(res, nums[j] - nums[i]);
                }
            }
        }

        return res;
    }
};