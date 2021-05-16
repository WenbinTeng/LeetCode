#include <vector>

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int e = std::min(steps / 2, arrLen - 1);
        std::vector<std::vector<int>> dp(2, std::vector<int>(e + 1));

        dp[steps & 1][0] = 1;

        for (int i = steps - 1; i >= 0; --i)
        {
            int curr =  i      & 1;
            int prev = (i + 1) & 1;
            for (int j = 0; j <= std::min(i, e); ++j)
            {
                dp[curr][j] = dp[prev][j];
                if (j - 1 >= 0) dp[curr][j] = (dp[curr][j] + dp[prev][j - 1]) % (int)(1e+9+7);
                if (j + 1 <= e) dp[curr][j] = (dp[curr][j] + dp[prev][j + 1]) % (int)(1e+9+7);
            }
        }

        return dp[0][0];
    }
};