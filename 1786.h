#include <vector>
#include <queue>

class Solution {
public:
    int countRestrictedPaths(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
        std::vector<int>  dis(n + 1, INT_MAX);
        std::vector<int>  mem(n + 1, -1);
        std::vector<bool> vis(n + 1, false);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(std::make_pair(edge[1], edge[2]));
            graph[edge[1]].push_back(std::make_pair(edge[0], edge[2]));
        }

        dis[n] = 0;

        pq.push(std::make_pair(0, n));

        while (!pq.empty())
        {
            auto [path, node] = pq.top();
            pq.pop();
            
            if (vis[node]) continue;

            vis[node] = true;
            dis[node] = path;

            for (const auto& [v, w] : graph[node])
            {
                if (dis[v] > dis[node] + w)
                {
                    dis[v] = dis[node] + w;
                    pq.push(std::make_pair(dis[v], v));
                }
            }
        }

        return dfs(graph, dis, mem, 1, n);
    }

private:
    int dfs(std::vector<std::vector<std::pair<int, int>>>& graph, std::vector<int>& dis, std::vector<int>& mem, int index, int n)
    {
        if (index == n) return 1;

        if (mem[index] != -1) return mem[index];

        int res = 0;

        for (const auto& [v, w] : graph[index])
        {
            if (dis[v] < dis[index])
            {
                res = ((long long)res + dfs(graph, dis, mem, v, n)) % (int)(1e+9 + 7);
            }
        }

        return mem[index] = res;
    }
};