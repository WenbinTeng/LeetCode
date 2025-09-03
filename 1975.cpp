#include <algorithm>
#include <vector>

class Solution {
  public:
    long long maxMatrixSum(std::vector<std::vector<int>> &matrix) {
        long long res = 0;
        int absMin = INT_MAX;
        int negCnt = 0;
        bool hasZero = false;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int num = matrix[i][j];
                if (num < 0) {
                    negCnt++;
                } else if (num == 0) {
                    hasZero = true;
                }
                absMin = std::min(absMin, std::abs(num));
                res += std::abs(num);
            }
        }

        if ((negCnt % 2 == 1) && !hasZero) {
            res -= absMin * 2;
        }

        return res;
    }
};