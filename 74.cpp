#include <vector>

class Solution {
  public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int l = 0, r = m * n - 1; l <= r;) {
            int mid = (l + r) / 2;

            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] < target)
                l = mid + 1;
            else if (matrix[mid / n][mid % n] > target)
                r = mid - 1;
        }

        return false;
    }
};