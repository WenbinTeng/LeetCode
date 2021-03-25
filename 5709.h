#include <vector>

class Solution {
public:
    int maxAscendingSum(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        int res = 0;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];

            if (i > 0 && nums[i - 1] >= nums[i]) sum = nums[i];

            res = std::max(res, sum);
        }

        return res;
    }
};