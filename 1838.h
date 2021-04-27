#include <vector>
#include <algorithm>

class Solution {
public:
    int maxFrequency(std::vector<int>& nums, int k) {
        int res = 0;
        int l = 0;
        int r = 0;
        long long sum = 0;

        std::sort(nums.begin(), nums.end());

        while (r < nums.size())
        {
            sum += nums[r];
            while (1LL * nums[r] * (r - l + 1) - sum > k)
            {
                sum -= nums[l];
                ++l;
            }
            res = std::max(res, r - l + 1);
            ++r;
        }

        return res;
    }
};