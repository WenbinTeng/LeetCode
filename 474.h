#include <vector>
#include <string>

class Solution {
public:
    int findMaxForm(std::vector<std::string>& strs, int m, int n) {
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (const auto& str : strs)
        {
            int cnt[2] = {0, 0};

            for (const auto& c : str) c == '0' ? ++cnt[0] : ++cnt[1];

            for (int i = m; i >= cnt[0]; --i)
            {
                for (int j = n; j >= cnt[1]; --j)
                {
                    dp[i][j] = std::max(dp[i][j], dp[i - cnt[0]][j - cnt[1]] + 1);
                }
            }
        }

        return dp[m][n];
    }
};