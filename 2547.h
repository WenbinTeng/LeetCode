#include <vector>

class Solution {
public:
    int minCost(std::vector<int> &nums, int K) {
        std::vector<long long> dp(nums.size() + 1, 1e+18);
        
        dp[0] = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            std::vector<int> cnt(nums.size(), 0);
            for (int j = i - 1, t = 0; j >= 0; --j) {
                int x = ++cnt[nums[j]];
                if (x == 2)
                    t += 2;
                else if (x > 2)
                    t++;
                dp[i] = std::min(dp[i], dp[j] + t + K);
            }
        }

        return dp.back();
    }
};