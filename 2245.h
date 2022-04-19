#include <vector>

class Solution {
public:
    int maxTrailingZeros(std::vector<std::vector<int>>& grid) {
        int res = 0;
        std::vector<std::vector<int>> rowCnt2(grid.size(), std::vector<int>(grid[0].size()));
        std::vector<std::vector<int>> rowCnt5(grid.size(), std::vector<int>(grid[0].size()));
        std::vector<std::vector<int>> colCnt2(grid.size(), std::vector<int>(grid[0].size()));
        std::vector<std::vector<int>> colCnt5(grid.size(), std::vector<int>(grid[0].size()));

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                int t = grid[i][j];
                int cnt2 = 0;
                int cnt5 = 0;

                while (t % 2 == 0)
                {
                    t /= 2;
                    ++cnt2;
                }

                t = grid[i][j];

                while (t % 5 == 0)
                {
                    t /= 5;
                    ++cnt5;
                }

                if (i == 0)
                {
                    colCnt2[i][j] = cnt2;
                    colCnt5[i][j] = cnt5;
                }
                else
                {
                    colCnt2[i][j] = colCnt2[i - 1][j] + cnt2;
                    colCnt5[i][j] = colCnt5[i - 1][j] + cnt5;
                }

                if (j == 0)
                {
                    rowCnt2[i][j] = cnt2;
                    rowCnt5[i][j] = cnt5;
                }
                else
                {
                    rowCnt2[i][j] = rowCnt2[i][j - 1] + cnt2;
                    rowCnt5[i][j] = rowCnt5[i][j - 1] + cnt5;
                }
            }
        }

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                int t = grid[i][j];
                int cnt2 = 0;
                int cnt5 = 0;

                while (t % 2 == 0)
                {
                    t /= 2;
                    ++cnt2;
                }

                t = grid[i][j];

                while (t % 5 == 0)
                {
                    t /= 5;
                    ++cnt5;
                }

                int prevRowCnt2 = j == 0 ? 0 :rowCnt2[i][j - 1];
                int nextRowCnt2 = rowCnt2[i].back() - rowCnt2[i][j];
                int prevColCnt2 = i == 0 ? 0 :colCnt2[i - 1][j];
                int nextColCnt2 = colCnt2.back()[j] - colCnt2[i][j];
                int prevRowCnt5 = j == 0 ? 0 : rowCnt5[i][j - 1];
                int nextRowCnt5 = rowCnt5[i].back() - rowCnt5[i][j];
                int prevColCnt5 = i == 0 ? 0 :colCnt5[i - 1][j];
                int nextColCnt5 = colCnt5.back()[j] - colCnt5[i][j];

                res = std::max(res, std::min(prevRowCnt2 + prevColCnt2 + cnt2, prevRowCnt5 + prevColCnt5 + cnt5));
                res = std::max(res, std::min(prevRowCnt2 + nextColCnt2 + cnt2, prevRowCnt5 + nextColCnt5 + cnt5));
                res = std::max(res, std::min(nextRowCnt2 + prevColCnt2 + cnt2, nextRowCnt5 + prevColCnt5 + cnt5));
                res = std::max(res, std::min(nextRowCnt2 + nextColCnt2 + cnt2, nextRowCnt5 + nextColCnt5 + cnt5));
            }
        }

        return res;
    }
};