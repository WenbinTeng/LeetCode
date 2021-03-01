#include <vector>
#include <algorithm>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        if (k == 1) return (double)*std::max_element(nums.begin(), nums.end());
        
        int winValue = 0;
        int maxValue = 0;
        int n = nums.size();

        for (int i = 0; i < k; i++)
        {
            winValue += nums[i];
        }

        maxValue = winValue;

        for (int i = k; i < n; i++)
        {
            winValue += nums[i];
            winValue -= nums[i - k];
            maxValue = std::max(maxValue, winValue);
        }

        return (double)maxValue / k;
    }
};