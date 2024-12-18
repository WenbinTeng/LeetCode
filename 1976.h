#include <vector>
#include <queue>

class Solution {
public:
    int countPaths(int n, std::vector<std::vector<int>>& roads) {
        const long long mod = 1e9 + 7;
        std::vector<std::vector<std::pair<int, int>>> e(n);
        for (const auto& road : roads) {
            int x = road[0], y = road[1], t = road[2];
            e[x].emplace_back(y, t);
            e[y].emplace_back(x, t);
        }
        std::vector<long long> dist(n, LLONG_MAX);
        std::vector<long long> ways(n);

        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> q;
        q.emplace(0, 0);
        dist[0] = 0;
        ways[0] = 1;
        
        while (!q.empty()) {
            auto [t, u] = q.top();
            q.pop();
            if (t > dist[u]) {
                continue;
            }
            for (auto &[v, w] : e[u]) {
                if (t + w < dist[v]) {
                    dist[v] = t + w;
                    ways[v] = ways[u];
                    q.emplace(t + w, v);
                } else if (t + w == dist[v]) {
                    ways[v] = (ways[u] + ways[v]) % mod;
                }
            }
        }
        
        return ways[n - 1];
    }
};