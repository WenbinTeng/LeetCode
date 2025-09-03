#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>>
    rangeAddQueries(int n, std::vector<std::vector<int>> &queries) {
        std::vector<std::vector<int>> res(n + 1, std::vector<int>(n + 1, 0));
        std::vector<std::vector<int>> diff(n + 1, std::vector<int>(n + 1, 0));

        for (const auto &query : queries) {
            int row1 = query[0];
            int col1 = query[1];
            int row2 = query[2];
            int col2 = query[3];

            diff[row1][col1] += 1;
            diff[row1][col2 + 1] -= 1;
            diff[row2 + 1][col1] -= 1;
            diff[row2 + 1][col2 + 1] += 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i + 1][j + 1] =
                    res[i + 1][j] + res[i][j + 1] - res[i][j] + diff[i][j];
            }
        }

        res.erase(res.begin());
        for (int i = 0; i < res.size(); ++i) {
            res[i].erase(res[i].begin());
        }

        return res;
    }
};