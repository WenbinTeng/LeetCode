#include <vector>

class Solution {
public:
    int minCost(int maxTime, std::vector<std::vector<int>>& edges, std::vector<int>& passingFees) {
        const int inf = INT_MAX / 2;
        int n = passingFees.size();
        int res = inf;
        std::vector<std::vector<int>> dp(maxTime + 1, std::vector<int>(n, inf));

        dp[0][0] = passingFees[0];

        for (int t = 1; t <= maxTime; t++) {
            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int cost = edge[2];
                if (cost <= t) {
                    dp[t][u] = std::min(dp[t][u], dp[t - cost][v] + passingFees[u]);
                    dp[t][v] = std::min(dp[t][v], dp[t - cost][u] + passingFees[v]);
                }
            }
        }

        for (int t = 1; t <= maxTime; t++) {
            res = std::min(res, dp[t][n - 1]);
        }

        return res == inf ? -1 : res;
    }
};