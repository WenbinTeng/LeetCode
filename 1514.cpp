#include <set>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    double maxProbability(int n, std::vector<std::vector<int>> &edges,
                          std::vector<double> &succProb, int start_node,
                          int end_node) {
        std::unordered_map<int, std::unordered_map<int, double>> adj;
        std::vector<double> dist(n, 0);
        std::set<std::pair<double, int>, std::greater<std::pair<double, int>>>
            s;

        for (int i = 0; i < succProb.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a][b] = succProb[i];
            adj[b][a] = succProb[i];
        }

        dist[start_node] = 1.0;
        s.insert({1.0, start_node});
        while (!s.empty()) {
            auto [prob_u, u] = *s.begin();
            s.erase(s.begin());
            for (auto &[v, prob_v] : adj[u]) {
                if (dist[u] * prob_v > dist[v]) {
                    if (dist[v] != 0) {
                        s.erase(s.find({dist[v], v}));
                    }
                    dist[v] = dist[u] * prob_v;
                    s.insert({dist[v], v});
                }
            }
        }

        return dist[end_node];
    }
};