#include <vector>

class Solution {
public:
    std::vector<int> minEdgeReversals(int n, std::vector<std::vector<int>> &edges) {
        adj.resize(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            adj[x].emplace_back(y, 1);
            adj[y].emplace_back(x, -1);
        }

        ans.resize(n);
        dfs(0, -1);
        reroot(0, -1);
        return ans;
    }

private:
    std::vector<std::vector<std::pair<int, int>>> adj;
    std::vector<int> ans;

    void dfs(int x, int fa) {
        for (auto &[y, dir] : adj[x]) {
            if (y != fa) {
                ans[0] += dir < 0;
                dfs(y, x);
            }
        }
    }

    void reroot(int x, int fa) {
        for (auto &[y, dir] : adj[x]) {
            if (y != fa) {
                ans[y] = ans[x] + dir;
                reroot(y, x);
            }
        }
    }
};