#include <vector>

class Solution {
  public:
    void gameOfLife(std::vector<std::vector<int>> &board) {
        std::vector<std::vector<int>> res(board.size(),
                                          std::vector<int>(board[0].size()));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                res[i][j] = pendingAlive(board, i, j);
            }
        }

        board = res;
    }

  private:
    int pendingAlive(std::vector<std::vector<int>> &board, int x, int y) {
        int cnt = 0;
        int m = board.size();
        int n = board[0].size();

        if (x > 0 && y > 0)
            cnt += board[x - 1][y - 1];
        if (y > 0)
            cnt += board[x][y - 1];
        if (x < m - 1 && y > 0)
            cnt += board[x + 1][y - 1];
        if (x > 0)
            cnt += board[x - 1][y];
        if (x < m - 1)
            cnt += board[x + 1][y];
        if (x > 0 && y < n - 1)
            cnt += board[x - 1][y + 1];
        if (y < n - 1)
            cnt += board[x][y + 1];
        if (x < m - 1 && y < n - 1)
            cnt += board[x + 1][y + 1];

        if (board[x][y] == 1) {
            return (cnt < 2 || cnt > 3) ? 0 : 1;
        } else {
            return cnt == 3 ? 1 : 0;
        }

        return 0;
    }
};