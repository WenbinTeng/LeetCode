#include <vector>
#include <deque>

class Solution {
public:
    int minimumObstacles(std::vector<std::vector<int>>& grid) {
        const int inf = 0x3f3f3f3f;
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dis(m, std::vector<int>(n, inf));
        std::vector<std::vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        std::deque<std::pair<int, int>> dq;

        dis[0][0] = 0;
        dq.push_back({0, 0});

        while (!dq.empty())
        {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (const auto& d : dir)
            {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                {
                    if (dis[nx][ny] > dis[x][y] + grid[nx][ny])
                    {
                        dis[nx][ny] = dis[x][y] + grid[nx][ny];
                        
                        if (grid[nx][ny] == 0)
                        {
                            dq.push_front({nx, ny});
                        }
                        else
                        {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }
        
        return dis[m - 1][n - 1];
    }
};