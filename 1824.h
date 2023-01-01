#include <vector>

class Solution {
public:
    int minSideJumps(std::vector<int> &obstacles) {
        int n = obstacles.size();
        std::vector<std::vector<int>> dp(3, std::vector<int>(n));

        dp[0][0] = 1;
        dp[1][0] = 0;
        dp[2][0] = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[j][i] = obstacles[i] - 1 == j ? MAX : std::min(dp[j][i - 1], std::min(dp[(j + 1) % 3][i - 1] + (obstacles[i] - 1 == (j + 1) % 3 ? MAX : 1), dp[(j + 2) % 3][i - 1] + (obstacles[i] - 1 == (j + 2) % 3 ? MAX : 1)));
            }
        }

        return std::min(dp[0].back(), std::min(dp[1].back(), dp[2].back()));
    }

private:
    int MAX = 0x3f3f3f3f;
};