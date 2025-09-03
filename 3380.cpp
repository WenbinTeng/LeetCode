#include <algorithm>
#include <map>
#include <set>
#include <vector>

class Solution {
  public:
    int maxRectangleArea(std::vector<std::vector<int>> &points) {
        int res = -1;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int xa = std::min(points[i][0], points[j][0]);
                int ya = std::min(points[i][1], points[j][1]);
                int xb = std::max(points[i][0], points[j][0]);
                int yb = std::max(points[i][1], points[j][1]);
                int cnt = 0;
                for (int k = 0; k < n; k++) {
                    if (points[k][0] < xa || points[k][0] > xb)
                        continue;
                    if (points[k][1] < ya || points[k][1] > yb)
                        continue;
                    if ((points[k][0] == xa || points[k][0] == xb) &&
                        (points[k][1] == ya || points[k][1] == yb)) {
                        cnt++;
                        continue;
                    }
                    cnt = 0;
                    break;
                }
                if (cnt == 4) {
                    int area = (xb - xa) * (yb - ya);
                    res = std::max(res, area);
                }
            }
        }

        return res;
    }
};