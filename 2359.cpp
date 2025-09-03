#include <unordered_set>
#include <vector>

class Solution {
  public:
    int closestMeetingNode(std::vector<int> &edges, int node1, int node2) {
        int n = edges.size();
        int res = -1;
        int dis = n;
        std::vector<int> d1(n, n);
        std::vector<int> d2(n, n);

        for (int i = 0, u = node1; u != -1; ++i, u = edges[u]) {
            if (d1[u] != n)
                break;
            d1[u] = i;
        }

        for (int i = 0, u = node2; u != -1; ++i, u = edges[u]) {
            if (d2[u] != n)
                break;
            d2[u] = i;
        }

        for (int i = 0; i < n; ++i) {
            int d = std::max(d1[i], d2[i]);
            if (dis > d) {
                dis = d;
                res = i;
            }
        }

        return res;
    }
};