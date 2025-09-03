#include <vector>

class Solution {
  public:
    int minMalwareSpread(std::vector<std::vector<int>> &graph,
                         std::vector<int> &initial) {
        int n = graph.size();

        std::vector<int> initialSet(n);
        for (int v : initial) {
            initialSet[v] = 1;
        }

        std::vector<std::vector<int>> infectedBy(n);
        for (int v : initial) {
            std::vector<int> infectedSet(n);
            dfs(graph, initialSet, infectedSet, v);
            for (int u = 0; u < n; u++) {
                if (infectedSet[u] == 1) {
                    infectedBy[u].push_back(v);
                }
            }
        }

        std::vector<int> count(n);
        for (int u = 0; u < n; u++) {
            if (infectedBy[u].size() == 1) {
                count[infectedBy[u][0]]++;
            }
        }

        int res = initial[0];
        for (int v : initial) {
            if (count[v] > count[res] || count[v] == count[res] && v < res) {
                res = v;
            }
        }

        return res;
    }

  private:
    void dfs(std::vector<std::vector<int>> &graph, std::vector<int> &initialSet,
             std::vector<int> &infectedSet, int v) {
        int n = graph.size();
        for (int u = 0; u < n; u++) {
            if (graph[v][u] == 0 || initialSet[u] == 1 || infectedSet[u] == 1) {
                continue;
            }
            infectedSet[u] = 1;
            dfs(graph, initialSet, infectedSet, u);
        }
    }
};