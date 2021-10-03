#include <vector>
#include <string>

class Solution {
public:
    bool placeWordInCrossword(std::vector<std::vector<char>>& board, std::string word) {
        for (auto& row : board)
        {
            row.insert(row.begin(), '#');
            row.insert(row.end(), '#');
        }
        board.insert(board.begin(), std::vector<char>());
        board.insert(board.end(), std::vector<char>());
        board.front().insert(board.front().begin(), board[1].size(), '#');
        board.back().insert(board.back().begin(), board[1].size(), '#');

        for (int i = 1; i < board.size() - 1; ++i)
        {
            for (int j = 1; j < board[0].size(); ++j)
            {
                if (board[i][j] == ' ' || board[i][j] == word.front())
                {
                    if (match(board, word, i, j))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    const int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool match(std::vector<std::vector<char>>& board, std::string& word, int x, int y)
    {
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            int px = x - dir[i][0];
            int py = y - dir[i][1];

            if (board[px][py] == '#')
            {
                bool isMatch = true;

                for (int index = 1; index < word.size(); ++index)
                {
                    if (board[nx][ny] == ' ' || board[nx][ny] == word[index])
                    {
                        nx += dir[i][0];
                        ny += dir[i][1];
                    }
                    else
                    {
                        isMatch = false; break;
                    }
                }

                if (isMatch && board[nx][ny] == '#') return true;
            }
        }

        return false;
    }
};