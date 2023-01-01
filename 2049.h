#include <vector>

class Solution {
public:
    int countHighestScoreNodes(std::vector<int> &parents) {
        n = parents.size();
        cnt = std::vector<int>(n);
        adj = std::vector<std::vector<int>>(n);
        for (int i = 1; i < n; ++i) {
            adj[parents[i]].push_back(i);
        }

        dfs(0);

        return res;
    }

private:
    int n;
    int res = 0;
    long long max = 0;
    long long rem = 0;
    std::vector<int> cnt;
    std::vector<std::vector<int>> adj;

    void dfs(int u) {
        cnt[u] = 1;
        for (const auto v : adj[u]) {
            dfs(v);
            cnt[u] += cnt[v];
        }

        rem = std::max(1, n - cnt[u]);
        for (const auto v : adj[u]) {
            rem *= cnt[v];
        }

        if (max < rem) {
            max = rem;
            res = 1;
        } else if (max == rem) {
            ++res;
        }
    }
};