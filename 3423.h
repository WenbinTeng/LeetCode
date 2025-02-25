#include <vector>
#include <algorithm>

class Solution {
public:
    int maxAdjacentDistance(std::vector<int>& nums) {
        int res = std::abs(nums.front() - nums.back());

        for (int i = 1; i < nums.size(); i++)
             res = std::max(res, std::abs(nums[i] - nums[i - 1]));

        return res;
    }
};