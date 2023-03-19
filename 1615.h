#include <vector>

class Solution {
public:
    int maximalNetworkRank(int n, std::vector<std::vector<int>> &roads) {
        int res = 0;
        std::vector<std::vector<bool>> adj(n, std::vector<bool>(n, false));
        std::vector<int> degree(n, 0);

        for (auto v : roads) {
            adj[v[0]][v[1]] = true;
            adj[v[1]][v[0]] = true;
            degree[v[0]]++;
            degree[v[1]]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res = std::max(res, degree[i] + degree[j] - (adj[i][j] ? 1 : 0));
            }
        }

        return res;
    }
};