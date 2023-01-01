#include <cmath>
#include <numeric>
#include <queue>
#include <vector>

class Solution {
public:
    int minSkips(std::vector<int> &dist, int speed, int hoursBefore) {
        if (std::accumulate(dist.begin(), dist.end(), 0) / (double)speed > hoursBefore)
            return -1;

        std::vector<std::vector<double>> dp(1001, std::vector<double>(1001, 1e+7 + 1));

        dp[0][0] = dist[0] / (double)speed;

        for (int i = 1; i < dist.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i][j] = std::min(dp[i][j], std::ceil(dp[i - 1][j] - (1e-9)) + dist[i] / (double)speed);
                dp[i][j + 1] = std::min(dp[i][j + 1], dp[i - 1][j] + dist[i] / (double)speed);
            }
        }

        for (int i = 0; i < dist.size(); ++i) {
            if (dp[dist.size() - 1][i] <= hoursBefore)
                return i;
        }

        return -1;
    }
};