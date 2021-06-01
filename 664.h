#include <vector>
#include <string>

class Solution {
public:
    int strangePrinter(std::string s) {
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size()));

        for (int i = s.size() - 1; i >= 0; --i)
        {
            dp[i][i] = 1;

            for (int j = i + 1; j < s.size(); ++j)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = __INT_MAX__;

                    for (int k = i; k < j; ++k)
                    {
                        dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }

        return dp[0][s.size() - 1];
    }
};