#include <functional>
#include <vector>

class Solution {
public:
    int countPaths(std::vector<std::vector<int>> &grid) {
        int res = 0;
        int mod = 1e+9 + 7;
        const int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> mem(m, std::vector<int>(n, -1));

        std::function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (mem[i][j] != -1)
                return mem[i][j];

            int ret = 1;

            for (const auto &d : direction) {
                int x = i + d[0];
                int y = j + d[1];

                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > grid[i][j]) {
                    ret = (ret + dfs(x, y)) % mod;
                }
            }

            mem[i][j] = ret;
            return ret;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = (res + dfs(i, j)) % mod;
            }
        }

        return res;
    }
};