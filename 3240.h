#include <vector>

class Solution {
public:
    int minFlips(std::vector<std::vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int s = grid[i][j] + grid[i][n - 1 - j] + grid[m - 1 - i][j] + grid[m - 1 - i][n - 1 - j];
                res += std::min(s, 4 - s);
            }
        }

        int diff = 0;
        int cnt1 = 0;
        if (m % 2 == 1) {
            for (int j = 0; j < n / 2; j++) {
                if (grid[m / 2][j] ^ grid[m / 2][n - 1 - j])
                    diff++;
                else
                    cnt1 += grid[m / 2][j] * 2;
            }
        }
        if (n % 2 == 1) {
            for (int i = 0; i < m / 2; i++) {
                if (grid[i][n / 2] ^ grid[m - 1 - i][n / 2])
                    diff++;
                else
                    cnt1 += grid[i][n / 2] * 2;
            }
        }
        if (m % 2 == 1 && n % 2 == 1) {
            res += grid[m / 2][n / 2];
        }

        if (diff > 0) {
            res += diff;
        } else {
            res += cnt1 % 4;
        }

        return res;
    }
};