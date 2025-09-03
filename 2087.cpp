#include <vector>

class Solution {
  public:
    int minCost(std::vector<int> &startPos, std::vector<int> &homePos,
                std::vector<int> &rowCosts, std::vector<int> &colCosts) {
        int startX = startPos[0];
        int startY = startPos[1];
        int homeX = homePos[0];
        int homeY = homePos[1];
        int res = -rowCosts[startX] - colCosts[startY];

        if (startX > homeX)
            std::swap(startX, homeX);
        if (startY > homeY)
            std::swap(startY, homeY);

        for (int i = startX; i <= homeX; i++)
            res += rowCosts[i];
        for (int i = startY; i <= homeY; i++)
            res += colCosts[i];

        return res;
    }
};