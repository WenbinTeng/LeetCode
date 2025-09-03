#include <vector>

class Solution {
  public:
    int longestCycle(std::vector<int> &edges) {
        int res = -1;
        std::vector<int> timeStamp(edges.size(), -1);

        for (int u = 0, clock = 1; u < edges.size(); ++u) {
            if (timeStamp[u] != -1)
                continue;

            for (int v = u, start = clock; v != -1; v = edges[v]) {
                if (timeStamp[v] != -1) {
                    if (timeStamp[v] >= start)
                        res = std::max(res, clock - timeStamp[v]);
                    break;
                }
                timeStamp[v] = clock++;
            }
        }

        return res;
    }
};