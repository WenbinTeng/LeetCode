#include <vector>

class Solution {
public:
    long long maxOutput(int n, std::vector<std::vector<int>> &edges, std::vector<int> &price) {
        adj = std::vector<std::vector<int>>(n);
        for (const auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, price);

        return res;
    }

private:
    long long res;
    std::vector<std::vector<int>> adj;

    std::pair<long long, long long> dfs(int u, int p, std::vector<int> &price) {
        long long maxSum1 = price[u];
        long long maxSum2 = 0;

        for (const auto v : adj[u]) {
            if (v != p) {
                auto [sum1, sum2] = dfs(v, u, price);
                res = std::max(res, std::max(maxSum1 + sum2, maxSum2 + sum1));
                maxSum1 = std::max(maxSum1, sum1 + price[u]);
                maxSum2 = std::max(maxSum2, sum2 + price[u]);
            }
        }

        return {maxSum1, maxSum2};
    }
};