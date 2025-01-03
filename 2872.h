#include <vector>

class Solution {
public:
    int maxKDivisibleComponents(int n, std::vector<std::vector<int>>& edges, std::vector<int>& values, int k) {
        int res = 0;
        std::vector<std::vector<int>> adj(n);
        
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto &&dfs = [&](auto &&self, int u, int parent) -> long long {
            long long sum = values[u];
            for (auto v : adj[u]) {
                if (v != parent)
                    sum += self(self, v, u);
            }
            if (sum % k == 0)
                res++;
            return sum;
        };

        dfs(dfs, 0, -1);

        return res;
    }
};