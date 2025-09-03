#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<int>
    shortestAlternatingPaths(int n, std::vector<std::vector<int>> &redEdges,
                             std::vector<std::vector<int>> &blueEdges) {
        std::vector<int> res(n);
        std::vector<std::vector<std::vector<int>>> adj(
            2, std::vector<std::vector<int>>(n));
        std::vector<std::vector<int>> dist(2, std::vector<int>(n, INT_MAX));
        std::queue<std::pair<int, int>> q;

        for (const auto &e : redEdges) {
            adj[0][e[0]].push_back(e[1]);
        }
        for (const auto &e : blueEdges) {
            adj[1][e[0]].push_back(e[1]);
        }

        dist[0][0] = 0;
        dist[1][0] = 0;
        q.push({0, 0});
        q.push({0, 1});
        while (!q.empty()) {
            auto [x, t] = q.front();
            q.pop();
            for (auto y : adj[1 - t][x]) {
                if (dist[1 - t][y] != INT_MAX) {
                    continue;
                }
                dist[1 - t][y] = dist[t][x] + 1;
                q.push({y, 1 - t});
            }
        }

        for (int i = 0; i < n; i++) {
            res[i] = std::min(dist[0][i], dist[1][i]);
            if (res[i] == INT_MAX) {
                res[i] = -1;
            }
        }

        return res;
    }
};