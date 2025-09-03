#include <algorithm>
#include <vector>

class Solution {
  public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>> &points) {
        int res = 0;

        std::sort(points.begin(), points.end(),
                  [&](std::vector<int> &a, std::vector<int> &b) {
                      return a[0] < b[0];
                  });

        for (int i = 1; i < points.size(); ++i) {
            res = std::max(res, points[i][0] - points[i - 1][0]);
        }

        return res;
    }
};