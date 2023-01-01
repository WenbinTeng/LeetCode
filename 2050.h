#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
    int minimumTime(int n, std::vector<std::vector<int>> &relations, std::vector<int> &time) {
        std::vector<int> deg(n);
        std::vector<std::vector<int>> adj(n);
        for (auto &relation : relations) {
            int u = relation[0] - 1, v = relation[1] - 1;
            adj[u].push_back(v);
            deg[v]++;
        }

        std::queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 0) {
                q.emplace(i);
            }
        }

        std::vector<int> dp(n);
        while (!q.empty()) {
            auto u = q.front();
            dp[u] += time[u];
            q.pop();
            for (auto v : adj[u]) {
                dp[v] = std::max(dp[v], dp[u]);
                if (--deg[v] == 0) {
                    q.emplace(v);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};