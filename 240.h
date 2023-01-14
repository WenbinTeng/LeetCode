#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = n - 1;

        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] > target) {
                --y;
            } else {
                ++x;
            }
        }

        return false;
    }
};