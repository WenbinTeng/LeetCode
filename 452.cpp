#include <algorithm>
#include <vector>

class Solution {
  public:
    int findMinArrowShots(std::vector<std::vector<int>> &points) {
        int res = 0;

        std::sort(points.begin(), points.end(),
                  [](std::vector<int> &a, std::vector<int> &b) {
                      return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
                  });

        int start = points[0][0];
        int end = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            int nextStart = points[i][0];
            int nextEnd = points[i][1];

            if (end < nextStart) {
                start = nextStart;
                end = nextEnd;
                res++;
            } else {
                start = nextStart;
                end = std::min(end, nextEnd);
            }
        }

        return res + 1;
    }
};