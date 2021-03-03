#include <vector>

class Solution {
public:
    bool divisorGame(int N) {
        if (N == 1) return false;

        std::vector<int> dp(N + 1, false);

        dp[1] = 0;
        dp[2] = 1;

        for (int i = 3; i <= N; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                if (i % j == 0 && !dp[i - j])
                {
                    dp[i] = 1; break;
                }
            }
        }

        return dp.back();
    }
};