#include <queue>
#include <vector>

class Solution {
  public:
    int orangesRotting(std::vector<std::vector<int>> &grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int res = 0;
        int freshCnt = 0;
        std::queue<std::pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCnt++;
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    q.push({x - 1, y});
                    freshCnt--;
                }
                if (x + 1 < m && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    q.push({x + 1, y});
                    freshCnt--;
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    q.push({x, y - 1});
                    freshCnt--;
                }
                if (y + 1 < n && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2;
                    q.push({x, y + 1});
                    freshCnt--;
                }
                q.pop();
            }
            res++;
        }

        return freshCnt ? -1 : (res ? res - 1 : 0);
    }
};