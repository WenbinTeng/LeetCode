#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumLines(std::vector<std::vector<int>>& stockPrices) {
        if (stockPrices.size() == 1) return 0;

        std::sort(stockPrices.begin(), stockPrices.end());

        int res = 1;
        int dx = stockPrices[1][0] - stockPrices[0][0];
        int dy = stockPrices[1][1] - stockPrices[0][1];

        for (int i = 2; i < stockPrices.size(); ++i)
        {

            int _dx = stockPrices[i][0] - stockPrices[i - 1][0];
            int _dy = stockPrices[i][1] - stockPrices[i - 1][1];

            if ((long long)dy * _dx != (long long)dx * _dy)
            {
                ++res;
            }

            dx = _dx;
            dy = _dy;
        }

        return res;
    }
};