#include <vector>

class Solution {
  public:
    std::vector<int>
    shortestDistanceAfterQueries(int n,
                                 std::vector<std::vector<int>> &queries) {
        int dist = n - 1;
        std::vector<int> res;
        std::vector<int> roads(n);

        for (int i = 0; i < n; i++) {
            roads[i] = i + 1;
        }

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];
            int next = roads[u];
            roads[u] = std::max(next, v);
            while (next != -1 && next < v) {
                int t = roads[next];
                roads[next] = -1;
                next = t;
                dist--;
            }
            res.push_back(dist);
        }

        return res;
    }
};