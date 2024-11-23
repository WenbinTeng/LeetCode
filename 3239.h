#include <vector>

class Solution {
public:
    int minFlips(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = INT_MAX;
        int sum = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n / 2; j++) {
                sum += grid[i][j] ^ grid[i][n - 1 - j];
            }
        }

        res = sum;
        sum = 0;

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m / 2; i++) {
                sum += grid[i][j] ^ grid[m - 1 - i][j];
            }
        }

        res = std::min(res, sum);

        return res;
    }
};