#include <vector>

class Solution {
  public:
    int numIslands(std::vector<std::vector<char>> &grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int res = 0;

        auto dfs = [&](auto &&self, int x, int y) -> void {
            grid[x][y] = '0';
            if (x - 1 >= 0 && grid[x - 1][y] == '1')
                self(self, x - 1, y);
            if (x + 1 < m && grid[x + 1][y] == '1')
                self(self, x + 1, y);
            if (y - 1 >= 0 && grid[x][y - 1] == '1')
                self(self, x, y - 1);
            if (y + 1 < n && grid[x][y + 1] == '1')
                self(self, x, y + 1);
        };

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == '1') {
                    dfs(dfs, x, y);
                    res++;
                }
            }
        }

        return res;
    }
};