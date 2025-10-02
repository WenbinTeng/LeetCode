#include <vector>

class Solution {
  public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            int x = matrix[mid / n][mid % n];
            if (target == x) {
                return true;
            }
            if (x < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};