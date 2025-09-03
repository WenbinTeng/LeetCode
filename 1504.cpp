#include <vector>

class Solution {
  public:
    int numSubmat(std::vector<std::vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        int res = 0;
        std::vector<std::vector<int>> prevSum(m, std::vector<int>(n));

        for (int i = 0; i < m; i++) {
            prevSum[i][0] = mat[i][0];
            for (int j = 1; j < n; j++) {
                prevSum[i][j] = prevSum[i][j - 1] + mat[i][j];
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prevSum[i][j] += prevSum[i - 1][j];
            }
        }

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                for (int i = x; i < m; i++) {
                    for (int j = y; j < n; j++) {
                        int a1 = (x == 0 || y == 0) ? 0 : prevSum[x - 1][y - 1];
                        int a2 = (x == 0) ? 0 : prevSum[x - 1][j];
                        int a3 = (y == 0) ? 0 : prevSum[i][y - 1];
                        int a4 = prevSum[i][j];
                        int area = a4 - a3 - a2 + a1;
                        if (area == (i - x + 1) * (j - y + 1))
                            res++;
                        else
                            break;
                    }
                }
            }
        }

        return res;
    }
};