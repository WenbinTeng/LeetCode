#include <vector>

class Solution {
public:
    int countSubmatrices(std::vector<std::vector<int>>& grid, int k) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> prevSum(m, std::vector<int>(n));

        for (int i = 0; i < m; i++) {
            prevSum[i][0] = grid[i][0];
            for (int j = 1; j < n; j++) {
                prevSum[i][j] = prevSum[i][j - 1] + grid[i][j];
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                prevSum[i][j] += prevSum[i - 1][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (prevSum[i][j] <= k) {
                    res++;
                }
            }
        }

        return res;
    }
};