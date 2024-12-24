#include <vector>

class Solution {
public:
    int minimumOperationsToWriteY(std::vector<std::vector<int>>& grid) {
        int res = INT_MAX;

        res = std::min(res, setY(grid, 0, 1));
        res = std::min(res, setY(grid, 0, 2));
        res = std::min(res, setY(grid, 1, 0));
        res = std::min(res, setY(grid, 1, 2));
        res = std::min(res, setY(grid, 2, 0));
        res = std::min(res, setY(grid, 2, 1));

        return res;
    }

private:
    bool posY(int x, int y, int n) {
        int central = n / 2;

        if (x > central) {
            return y == central;
        } else {
            return (x == y) || (x + y == n - 1);
        }

        return false;
    }

    int setY(std::vector<std::vector<int>>& grid, int yVal, int bVal) {
        int cnt = 0;
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (posY(i, j, n)) {
                    if (grid[i][j] != yVal) {
                        cnt++;
                    }
                } else {
                    if (grid[i][j] != bVal) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};