#include <vector>

class Solution {
public:
    bool checkValid(std::vector<std::vector<int>> &matrix) {

        std::vector<std::vector<bool>> colFlag(matrix.size(), std::vector<bool>(matrix.size(), false));

        for (int i = 0; i < matrix.size(); ++i) {
            std::vector<bool> rowFlag(matrix.size(), false);

            for (int j = 0; j < matrix.size(); ++j) {
                colFlag[j][matrix[i][j] - 1] = true;
                rowFlag[matrix[i][j] - 1] = true;
            }

            for (int j = 0; j < matrix.size(); ++j) {
                if (!rowFlag[j])
                    return false;
            }
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                if (!colFlag[i][j])
                    return false;
            }
        }

        return true;
    }
};