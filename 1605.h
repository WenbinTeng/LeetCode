#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> restoreMatrix(std::vector<int> &rowSum, std::vector<int> &colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        std::vector<std::vector<int>> matrix(n, std::vector<int>(m, 0));

        for (int i = 0, j = 0; i < n && j < m;) {
            int v = std::min(rowSum[i], colSum[j]);
            matrix[i][j] = v;
            rowSum[i] -= v;
            colSum[j] -= v;
            if (rowSum[i] == 0)
                ++i;
            if (colSum[j] == 0)
                ++j;
        }

        return matrix;
    }
};