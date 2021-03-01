#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> res;

        int cnt = 0;
        for (int i = 0; i < (n + 1) / 2; ++i)
        {
            if (i == n / 2) cnt = res.size();

            if (col.find(i) != col.end()) continue;
            if (posDiag.find(0 - i) != col.end()) continue;
            if (negDiag.find(0 + i) != col.end()) continue;

            coor.push_back(std::make_pair(0, i));
            col.insert(i);
            posDiag.insert(0 - i);
            negDiag.insert(0 + i);

            backtrack(res, n, 1);

            coor.pop_back();
            col.erase(i);
            posDiag.erase(0 - i);
            negDiag.erase(0 + i);
        }

        if (n % 2 == 0) cnt = res.size();

        for (int i = 0; i < cnt; ++i)
        {
            std::vector<std::string> board = res[i];
            for (int j = 0; j < board.size(); ++j)
            {
                std::reverse(board[j].begin(), board[j].end());
            }
            res.push_back(board);
        }

        return res;
    }

private:
    std::vector<std::pair<int, int>> coor;
    std::unordered_set<int> col;
    std::unordered_set<int> posDiag;
    std::unordered_set<int> negDiag;

    void backtrack(std::vector<std::vector<std::string>> &res, int n, int row)
    {
        if (row == n)
        {
            std::vector<std::string> board(n);
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    board[i] += '.';
                }
            }
            for (const auto &[row, col] : coor)
            {
                board[row][col] = 'Q';
            }

            res.push_back(board);
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            if (col.find(i) != col.end()) continue;
            if (posDiag.find(row - i) != col.end()) continue;
            if (negDiag.find(row + i) != col.end()) continue;

            coor.push_back(std::make_pair(row, i));
            col.insert(i);
            posDiag.insert(row - i);
            negDiag.insert(row + i);

            backtrack(res, n, row + 1);

            coor.pop_back();
            col.erase(i);
            posDiag.erase(row - i);
            negDiag.erase(row + i);
        }
    }
};