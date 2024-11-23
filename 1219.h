#include <vector>

class Solution {
public:
    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        int res = 0;
        myGrid = grid;

        for (int i = 0; i < grid.size (); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                res = std::max(res, dig(i, j));
            }
        }

        return res;
    }

private:
    std::vector<std::vector<int>> myGrid;

    int dig(int x, int y) {
        int curr = myGrid[x][y];
        
        if (myGrid[x][y] == 0)
            return 0;
        else
            myGrid[x][y] = 0;

        int sum = 0;

        if (x - 1 >= 0)
            sum = dig(x - 1, y);
        if (x + 1 < myGrid.size())
            sum = std::max(sum, dig(x + 1, y));
        if (y - 1 >= 0)
            sum = std::max(sum, dig(x, y - 1));
        if (y + 1 < myGrid[0].size())
            sum = std::max(sum, dig(x, y + 1));

        myGrid[x][y] = curr;
        return curr + sum;
    }
};