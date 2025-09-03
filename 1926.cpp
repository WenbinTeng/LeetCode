#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int nearestExit(std::vector<std::vector<char>> &maze,
                    std::vector<int> &entrance) {
        int res = 0;
        int m = maze.size();
        int n = maze[0].size();
        const int xDir[4] = {-1, 0, 1, 0};
        const int yDir[4] = {0, -1, 0, 1};
        std::unordered_set<long long> visited;
        std::queue<long long> q;

        auto makeKey = [](int x, int y) -> long long {
            return ((long long)x << 32) + y;
        };

        auto decoupleKey = [](long long k) -> std::pair<int, int> {
            return {k >> 32, (int)k};
        };

        q.push(makeKey(entrance[0], entrance[1]));
        visited.insert(q.front());
        while (true) {
            for (int i = 0, size = q.size(); i < size; i++) {
                auto front = q.front();
                auto [x, y] = decoupleKey(front);
                q.pop();
                if ((x == 0 || x == m - 1 || y == 0 || y == n - 1) &&
                    maze[x][y] == '.' &&
                    !(x == entrance[0] && y == entrance[1]))
                    return res;
                for (int i = 0; i < 4; i++) {
                    int nx = x + xDir[i];
                    int ny = y + yDir[i];
                    long long nkey = makeKey(nx, ny);
                    if ((nx >= 0 && nx < m && ny >= 0 && ny < n) &&
                        maze[nx][ny] == '.' && visited.count(nkey) == 0) {
                        q.push(nkey);
                        visited.insert(nkey);
                    }
                }
            }
            if (q.empty())
                return -1;
            res++;
        }

        return res;
    }
};