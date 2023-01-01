#include <vector>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    row[i][board[i][j] - '1'] = true;
                    col[j][board[i][j] - '1'] = true;
                    sub[(i / 3) * 3 + j / 3][board[i][j] - '1'] = true;
                } else {
                    this->blankVec.push_back(std::make_pair(i, j));
                }
            }
        }

        generate(board, 0);
    }

private:
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool sub[9][9] = {false};
    bool valid = false;
    std::vector<std::pair<int, int>> blankVec;

    void generate(std::vector<std::vector<char>> &board, int blankIndex) {
        if (blankIndex == blankVec.size()) {
            this->valid = true;
            return;
        }

        auto [i, j] = blankVec[blankIndex];

        for (int k = 0; k < 9; k++) {
            if (!row[i][k] && !col[j][k] && !sub[(i / 3) * 3 + j / 3][k]) {
                board[i][j] = k + '1';

                row[i][k] = true;
                col[j][k] = true;
                sub[(i / 3) * 3 + j / 3][k] = true;

                generate(board, blankIndex + 1);

                row[i][k] = false;
                col[j][k] = false;
                sub[(i / 3) * 3 + j / 3][k] = false;
            }
            if (valid)
                break;
        }
    }
};