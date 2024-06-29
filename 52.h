#include <unordered_set>
#include <vector>

class Solution {
public:
    int totalNQueens(int n) {
        int cnt = 0;
        res = 0;

        for (int i = 0; i < (n + 1) / 2; i++) {
            if (i == n / 2)
                cnt = res;

            if (col.find(i) != col.end())
                continue;
            if (posDiag.find(0 - i) != col.end())
                continue;
            if (negDiag.find(0 + i) != col.end())
                continue;

            coor.push_back(std::make_pair(0, i));
            col.insert(i);
            posDiag.insert(0 - i);
            negDiag.insert(0 + i);

            backtrack(n, 1);

            coor.pop_back();
            col.erase(i);
            posDiag.erase(0 - i);
            negDiag.erase(0 + i);
        }

        return n % 2 == 0 ? res * 2 : cnt * 2 + res - cnt;
    }

private:
    int res;
    std::vector<std::pair<int, int>> coor;
    std::unordered_set<int> col;
    std::unordered_set<int> posDiag;
    std::unordered_set<int> negDiag;

    void backtrack(int n, int row) {
        if (row == n) {
            res++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (col.find(i) != col.end())
                continue;
            if (posDiag.find(row - i) != col.end())
                continue;
            if (negDiag.find(row + i) != col.end())
                continue;

            coor.push_back(std::make_pair(row, i));
            col.insert(i);
            posDiag.insert(row - i);
            negDiag.insert(row + i);

            backtrack(n, row + 1);

            coor.pop_back();
            col.erase(i);
            posDiag.erase(row - i);
            negDiag.erase(row + i);
        }
    }
};