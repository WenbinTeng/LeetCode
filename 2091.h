#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumDeletions(std::vector<int>& nums) {
        int n = nums.size();
        int res;
        int minValue = INT_MAX;
        int minIndex = -1;
        int maxValue = INT_MIN;
        int maxIndex = -1;

        for (int i = 0; i < n; ++i)
        {
            if (minValue > nums[i])
            {
                minValue = nums[i];
                minIndex = i;
            }
            if (maxValue < nums[i])
            {
                maxValue = nums[i];
                maxIndex = i;
            }
        }

        int minL = minIndex + 1;
        int minR = n - minIndex;
        int maxL = maxIndex + 1;
        int maxR = n - maxIndex;

        if (minIndex <= maxIndex)
        {
            res = std::min(minL + maxR, std::min(maxL, minR));
        }
        else
        {
            res = std::min(maxL + minR, std::min(minL, maxR));
        }

        return res;
    }
};