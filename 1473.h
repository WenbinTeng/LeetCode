#include <vector>

class Solution {
public:
    int minCost(std::vector<int>& houses, std::vector<std::vector<int>>& cost, int m, int n, int target) {
        int res = 0x3f3f3f3f;
        int inf = 0x3f3f3f3f;
        std::vector<std::vector<std::vector<int>>> dp(m + 1, std::vector<std::vector<int>>(n + 1, std::vector<int>(target + 1)));

        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                dp[i][j][0] = inf;
            }
        }

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                for (int k = 1; k <= target; ++k)
                {
                    if (k > i) {dp[i][j][k] = inf; continue;}

                    if (houses[i - 1] == 0)
                    {
                        dp[i][j][k] = dp[i - 1][j][k];

                        for (int t = 1; t <= n; ++t)
                        {
                            if (j != t)
                            {
                                dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][t][k - 1]);
                            }
                        }

                        dp[i][j][k] += cost[i - 1][j - 1];
                    }
                    else
                    {
                        if (j == houses[i - 1])
                        {
                            dp[i][j][k] = dp[i - 1][j][k];

                            for (int t = 1; t <= n; ++t)
                            {
                                if (j != t)
                                {
                                    dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][t][k - 1]);
                                }
                            }
                        }
                        else
                        {
                            dp[i][j][k] = inf;
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            res = std::min(res, dp[m][i][target]);
        }

        return res >= inf ? -1 : res;
    }
};