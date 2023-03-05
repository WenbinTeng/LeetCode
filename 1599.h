#include <vector>

class Solution {
public:
    int minOperationsMaxProfit(std::vector<int> &customers, int boardingCost, int runningCost) {
        int res = -1;
        int max = 0;
        int brdCnt = 0;
        int gndCnt = 0;

        for (int i = 0; i<customers.size() | gndCnt> 0; ++i) {
            if (i < customers.size()) {
                gndCnt += customers[i];
            }
            if (gndCnt >= 4) {
                gndCnt -= 4;
                brdCnt += 4;
            } else {
                brdCnt += gndCnt;
                gndCnt = 0;
            }
            if (brdCnt * boardingCost - runningCost * (i + 1) > max) {
                res = i + 1;
                max = brdCnt * boardingCost - runningCost * (i + 1);
            }
        }

        return res;
    }
};