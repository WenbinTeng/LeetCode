#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool sub[9][9] = {false};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    char a = board[i][j];
                    if (row[i][board[i][j] - '1']) return false; else row[i][board[i][j] - '1'] = true;
                    if (col[j][board[i][j] - '1']) return false; else col[j][board[i][j] - '1'] = true;
                    if (sub[(i / 3) * 3 + j / 3][board[i][j] - '1']) return false; else sub[(i / 3) * 3 + j / 3][board[i][j] - '1'] = true;
                }
            }
        }

        return true;
    }
};