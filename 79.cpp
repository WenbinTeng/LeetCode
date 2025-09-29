#include <string>
#include <vector>

class Solution {
  public:
    bool exist(std::vector<std::vector<char>> &board, std::string word) {
        const int m = board.size();
        const int n = board[0].size();
        bool res = false;
        std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));

        auto backtrack = [&](auto &&self, int x, int y, int index) -> void {
            if (index == word.size()) {
                res = true;
                return;
            }

            if (x - 1 >= 0 && !visited[x - 1][y] &&
                board[x - 1][y] == word[index] && !res) {
                visited[x - 1][y] = 1;
                self(self, x - 1, y, index + 1);
                visited[x - 1][y] = 0;
            }
            if (x + 1 < m && !visited[x + 1][y] &&
                board[x + 1][y] == word[index] && !res) {
                visited[x + 1][y] = 1;
                self(self, x + 1, y, index + 1);
                visited[x + 1][y] = 0;
            }
            if (y - 1 >= 0 && !visited[x][y - 1] &&
                board[x][y - 1] == word[index] && !res) {
                visited[x][y - 1] = 1;
                self(self, x, y - 1, index + 1);
                visited[x][y - 1] = 0;
            }
            if (y + 1 < n && !visited[x][y + 1] &&
                board[x][y + 1] == word[index] && !res) {
                visited[x][y + 1] = 1;
                self(self, x, y + 1, index + 1);
                visited[x][y + 1] = 0;
            }
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!res && board[i][j] == word[0]) {
                    visited[i][j] = 1;
                    backtrack(backtrack, i, j, 1);
                    visited[i][j] = 0;
                }
            }
        }

        return res;
    }
};