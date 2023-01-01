#include <unordered_set>
#include <vector>

class Solution {
public:
    int maximumANDSum(std::vector<int> &nums, int numSlots) {
        int res = 0;
        std::vector<int> dp(1 << (numSlots * 2));

        for (int i = 0; i < dp.size(); ++i) {
            int tmp = i;
            int cnt = 0;

            while (tmp) {
                if (tmp & 1)
                    ++cnt;
                tmp = tmp >> 1;
            }

            if (cnt >= nums.size())
                continue;

            for (int j = 0; j < numSlots * 2; ++j) {
                if ((i & (1 << j)) == 0) {
                    int s = i | (1 << j);
                    dp[s] = std::max(dp[s], dp[i] + (((j % numSlots) + 1) & nums[cnt]));
                    res = std::max(res, dp[s]);
                }
            }
        }

        return res;
    }
};