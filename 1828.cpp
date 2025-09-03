#include <vector>

class Solution {
  public:
    std::vector<int> countPoints(std::vector<std::vector<int>> &points,
                                 std::vector<std::vector<int>> &queries) {
        std::vector<int> res(queries.size());

        for (int i = 0; i < queries.size(); ++i) {
            int cx = queries[i][0];
            int cy = queries[i][1];
            int cr = queries[i][2];

            for (int j = 0; j < points.size(); ++j) {
                int px = points[j][0];
                int py = points[j][1];

                if ((cx - px) * (cx - px) + (cy - py) * (cy - py) <= cr * cr)
                    ++res[i];
            }
        }

        return res;
    }
};