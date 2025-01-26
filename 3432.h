#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int countPartitions(std::vector<int>& nums) {
        int res = 0;
        int lsum = 0;
        int rsum = std::accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < nums.size() - 1; i++) {
            lsum += nums[i];
            rsum -= nums[i];
            if (std::abs(lsum - rsum) % 2 == 0)
                res++;
        }

        return res;
    }
};