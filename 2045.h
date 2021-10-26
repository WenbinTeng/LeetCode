#include <vector>
#include <queue>

class Solution {
public:
    int secondMinimum(int n, std::vector<std::vector<int>>& edges, int time, int change) {
        const int INF = 0x3f3f3f3f;

        std::vector< std::vector<int>> adj(n);
        for (const auto &edge : edges)
        {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        std::queue<int> q;
        std::vector<int> d(n, INF);
        std::vector<bool> available(n);
        d[0] = 0;
        q.emplace(0);
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            for (const auto v : adj[u])
            {
                if (d[v] > d[u] + 1)
                {
                    d[v] = d[u] + 1;
                    q.emplace(v);
                }
                else if (d[u] == d[v] || (available[u] && d[u] <= d[v]))
                {
                    if (!available[v]) q.emplace(v);
                    available[v] = true;
                }
            }
        }

        int dist = available[n - 1] ? d[n - 1] + 1 : d[n - 1] + 2;
        int t = 0;
        while (dist--)
        {
            t += time;
            if (dist > 0 && t % (2 * change) >= change) t = (t / (2 * change) + 1) * 2 * change;
        }
        
        return t;
    }
};