#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int res = 0;
        int end = 0;
        int maxPos = 0;

        for (int i = 0, n = nums.size() - 1; i < n; i++)
        {
            if (maxPos >= i)
            {
                maxPos = std::max(maxPos, i + nums[i]);

                if (i == end)
                {
                    end = maxPos;
                    res++;
                }
            }
        }

        return res;
    }
};