#include <vector>

class Solution {
  public:
    int maximalPathQuality(std::vector<int> &values,
                           std::vector<std::vector<int>> &edges, int maxTime) {
        this->maxTime = maxTime;
        this->currTime = 0;
        this->maxValue = 0;
        this->currValue = 0;
        this->values = values;
        adj = std::vector<std::vector<std::pair<int, int>>>(values.size());
        vis = std::vector<int>(values.size());
        for (const auto &e : edges) {
            int u = e[0], v = e[1], t = e[2];
            adj[u].emplace_back(v, t);
            adj[v].emplace_back(u, t);
        }

        dfs(0);
        return maxValue;
    }

  private:
    int maxTime;
    int currTime;
    int maxValue;
    int currValue;
    std::vector<int> vis, values;
    std::vector<std::vector<std::pair<int, int>>> adj;

    void dfs(int u) {
        if (!vis[u])
            currValue += values[u];

        ++vis[u];

        if (u == 0)
            maxValue = std::max(maxValue, currValue);

        for (auto [v, time] : adj[u]) {
            if (currTime + time <= maxTime) {
                currTime += time;
                dfs(v);
                currTime -= time;
            }
        }

        --vis[u];

        if (!vis[u])
            currValue -= values[u];
    }
};