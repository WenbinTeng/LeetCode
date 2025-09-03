#include <vector>

class Solution {
  public:
    std::vector<int>
    shortestDistanceAfterQueries(int n,
                                 std::vector<std::vector<int>> &queries) {
        std::vector<int> res;
        std::vector<int> dp(n);
        std::vector<std::vector<int>> prev(n);

        for (int i = 0; i < n; i++) {
            dp[i] = i;
            prev[i].push_back(i - 1);
        }

        for (auto &q : queries) {
            prev[q[1]].push_back(q[0]);
            for (int v = q[1]; v < n; v++) {
                for (auto u : prev[v]) {
                    dp[v] = std::min(dp[v], dp[u] + 1);
                }
            }
            res.push_back(dp.back());
        }

        return res;
    }
};