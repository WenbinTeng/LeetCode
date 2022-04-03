#include <vector>

class Solution {
public:
    int maxValueOfCoins(std::vector<std::vector<int>>& piles, int k) {
        int sum = 0;
        std::vector<int> dp(k + 1);

        for (auto& pile : piles)
        {
            for (int i = 1; i < pile.size(); ++i)
            {
                pile[i] += pile[i - 1];
            }

            sum = std::min(sum + (int)pile.size(), k);

            for (int j = sum; j > 0; --j)
            {
                for (int t = 0; t < std::min(j, (int)pile.size()); ++t)
                {
                    dp[j] = std::max(dp[j], dp[j - t - 1] + pile[t]);
                }
            }
        }

        return dp[k];
    }
};