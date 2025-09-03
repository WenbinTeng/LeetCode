#include <unordered_map>
#include <vector>

class Solution {
  public:
    int numberOfSets(int n, int maxDistance,
                     std::vector<std::vector<int>> &roads) {
        const int inf = 0x3f3f3f3f;
        int res = 0;
        std::vector<int> opened(n);
        std::vector<std::vector<int>> adj(n, std::vector<int>(n));

        auto floyd = [&]() {
            for (int k = 0; k < n; k++)
                if (opened[k] > 0)
                    for (int i = 0; i < n; i++)
                        if (opened[i] > 0)
                            for (int j = i + 1; j < n; j++)
                                if (opened[j] > 0)
                                    adj[i][j] = adj[j][i] = std::min(
                                        adj[i][j], adj[i][k] + adj[k][j]);
        };

        auto validate = [&]() {
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if (opened[i] > 0) {
                    for (int j = i + 1; j < n; j++) {
                        if (opened[j] > 0) {
                            if (adj[i][j] > maxDistance) {
                                valid = false;
                                break;
                            }
                        }
                    }
                    if (!valid)
                        break;
                }
            }
            return valid;
        };

        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                opened[i] = mask & (1 << i);
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j)
                        adj[i][j] = 0;
                    else
                        adj[i][j] = inf;
                }
            }
            for (auto &road : roads) {
                int u = road[0];
                int v = road[1];
                int w = road[2];
                if (opened[u] > 0 && opened[v] > 0) {
                    adj[u][v] = std::min(adj[u][v], w);
                    adj[v][u] = std::min(adj[v][u], w);
                }
            }
            floyd();
            if (validate())
                res++;
        }

        return res;
    }
};