#include <vector>

class Solution {
public:
    int countHousePlacements(int n) {
        std::vector<int> dp(n + 1);

        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % (int)(1e+9 + 7);
        }

        return (long long)dp.back() * dp.back() % (long long)(1e+9 + 7);
    }
};