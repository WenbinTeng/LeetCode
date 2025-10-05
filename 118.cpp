#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> res(numRows);

        res[0].push_back(1);
        for (int i = 1; i < numRows; i++) {
            int numCols = i + 1;
            res[i].resize(numCols);
            res[i][0] = 1;
            res[i][numCols - 1] = 1;
            for (int j = 1; j < numCols - 1; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }

        return res;
    }
};