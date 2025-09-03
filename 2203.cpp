#include <queue>
#include <vector>

class Solution {
  public:
    long long minimumWeight(int n, std::vector<std::vector<int>> &edges,
                            int src1, int src2, int dest) {
        long long res = INF;
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        std::vector<std::vector<std::pair<int, int>>> rev(n);

        for (const auto &edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            rev[edge[1]].push_back({edge[0], edge[2]});
        }

        std::vector<long long> d1 = dijkstra(adj, src1);
        std::vector<long long> d2 = dijkstra(adj, src2);
        std::vector<long long> dd = dijkstra(rev, dest);

        for (int i = 0; i < adj.size(); ++i) {
            res = std::min(res, d1[i] + d2[i] + dd[i]);
        }

        return res == INF ? -1 : res;
    }

  private:
    const long long INF = (int)1e+12;
    std::vector<long long>
    dijkstra(std::vector<std::vector<std::pair<int, int>>> &adj, int src) {
        std::priority_queue<std::pair<long long, int>,
                            std::vector<std::pair<long long, int>>,
                            std::greater<std::pair<long long, int>>>
            pq;
        std::vector<long long> dis(adj.size(), INF);

        pq.push({0, src});
        dis[src] = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dis[u])
                continue;

            for (auto [v, w] : adj[u]) {
                if (dis[v] > d + w) {
                    dis[v] = d + w;
                    pq.push({dis[v], v});
                }
            }
        }

        return dis;
    }
};