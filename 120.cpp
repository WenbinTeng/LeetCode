#include <algorithm>
#include <vector>

class Solution {
  public:
    int minimumTotal(std::vector<std::vector<int>> &triangle) {
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    triangle[i][j] = triangle[i - 1][j] + triangle[i][j];
                    continue;
                }
                if (j == i) {
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
                    continue;
                }

                triangle[i][j] =
                    std::min(triangle[i - 1][j - 1], triangle[i - 1][j]) +
                    triangle[i][j];
            }
        }

        return *std::min_element(triangle.back().begin(),
                                 triangle.back().end());
    }
};