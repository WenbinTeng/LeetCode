#include <string>
#include <vector>

class Solution {
public:
    bool exist(std::vector<std::vector<char>> &board, std::string word) {
        int m = board.size();
        int n = board[0].size();
        std::vector<std::vector<bool>> vis(m, std::vector<bool>(n, false));

        for (int i = 0; i < m * n && !finded; ++i) {
            if (board[i / n][i % n] == word[0]) {
                vis[i / n][i % n] = true;
                dfs(board, word, vis, 1, i / n, i % n);
                vis[i / n][i % n] = false;
            }
        }

        return finded;
    }

private:
    bool finded;

    void dfs(std::vector<std::vector<char>> &board, std::string &word, std::vector<std::vector<bool>> &vis, int pos, int i, int j) {
        if (finded)
            return;

        if (pos == word.size()) {
            finded = true;
            return;
        }

        if (i > 0 && board[i - 1][j] == word[pos] && !vis[i - 1][j]) {
            vis[i - 1][j] = true;
            dfs(board, word, vis, pos + 1, i - 1, j);
            vis[i - 1][j] = false;
        }
        if (j > 0 && board[i][j - 1] == word[pos] && !vis[i][j - 1]) {
            vis[i][j - 1] = true;
            dfs(board, word, vis, pos + 1, i, j - 1);
            vis[i][j - 1] = false;
        }
        if (i < board.size() - 1 && board[i + 1][j] == word[pos] && !vis[i + 1][j]) {
            vis[i + 1][j] = true;
            dfs(board, word, vis, pos + 1, i + 1, j);
            vis[i + 1][j] = false;
        }
        if (j < board[0].size() - 1 && board[i][j + 1] == word[pos] && !vis[i][j + 1]) {
            vis[i][j + 1] = true;
            dfs(board, word, vis, pos + 1, i, j + 1);
            vis[i][j + 1] = false;
        }
    }
};