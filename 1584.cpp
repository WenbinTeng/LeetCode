#include <algorithm>
#include <set>
#include <vector>

class Solution {
  public:
    int minCostConnectPoints(std::vector<std::vector<int>> &points) {
        int n = points.size();
        int res = 0;
        std::vector<std::vector<int>> dist(n, std::vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int xi = points[i][0];
                int yi = points[i][1];
                int xj = points[j][0];
                int yj = points[j][1];
                int d = std::abs(xi - xj) + std::abs(yi - yj);

                dist[i][j] = d;
                dist[j][i] = d;
            }
        }

        std::set<int> connected;
        std::set<int> unconnected;

        connected.insert(0);
        for (int i = 1; i < n; i++)
            unconnected.insert(i);

        while (!unconnected.empty()) {
            int minDist = INT_MAX;
            int minNode = -1;

            for (auto &u : connected) {
                for (auto &v : unconnected) {
                    int d = dist[u][v];
                    if (minDist > d) {
                        minDist = d;
                        minNode = v;
                    }
                }
            }

            connected.insert(minNode);
            unconnected.erase(minNode);
            res += minDist;
        }

        return res;
    }
};