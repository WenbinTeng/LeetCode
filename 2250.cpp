#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<int> countRectangles(std::vector<std::vector<int>> &rectangles,
                                     std::vector<std::vector<int>> &points) {
        std::vector<int> res;
        int maxY = 0;

        std::vector<std::vector<int>> coor(101);

        for (const auto &rectangle : rectangles) {
            int x = rectangle[0];
            int y = rectangle[1];

            maxY = std::max(maxY, y);

            coor[y].push_back(x);
        }

        for (int i = 0; i < coor.size(); ++i) {
            std::sort(coor[i].begin(), coor[i].end());
        }

        for (const auto &point : points) {
            int cnt = 0;
            int px = point[0];
            int py = point[1];

            for (int i = py; i <= maxY; ++i) {
                auto iter =
                    std::lower_bound(coor[i].begin(), coor[i].end(), px);
                cnt += coor[i].end() - iter;
            }

            res.push_back(cnt);
        }

        return res;
    }
};