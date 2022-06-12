#include <vector>
#include <algorithm>

class Solution {
public:
    int partitionArray(std::vector<int>& nums, int k) {
        int res = 1;
        int num = 0;

        std::sort(nums.begin(), nums.end());

        num = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] - num > k)
            {
                num = nums[i];
                ++res;
            }
        }

        return res;
    }
};