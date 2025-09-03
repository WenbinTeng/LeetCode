#include <vector>

class Solution {
  public:
    int numSquares(int n) {
        std::vector<int> dp(n + 1);

        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int min = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                min = std::min(min, dp[i - j * j]);
            }
            dp[i] = min + 1;
        }

        return dp[n];
    }
};