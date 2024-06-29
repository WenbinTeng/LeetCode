#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>> &matrix) {
        bool firstRowSet = false;
        bool firstColSet = false;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0) {
                firstColSet = true;
                break;
            }
        for (int i = 0; i < n; i++)
            if (matrix[0][i] == 0) {
                firstRowSet = true;
                break;
            }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (firstColSet) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
        if (firstRowSet) {
            for (int i = 0; i < n; i++)
                matrix[0][i] = 0;
        }
    }
};