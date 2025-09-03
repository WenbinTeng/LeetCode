#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<int> luckyNumbers(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<int> res;
        std::vector<int> rowMin(m, INT_MAX);
        std::vector<int> colMax(n, INT_MIN);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rowMin[i] > matrix[i][j]) {
                    rowMin[i] = matrix[i][j];
                }
                if (colMax[j] < matrix[i][j]) {
                    colMax[j] = matrix[i][j];
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }

        return res;
    }
};