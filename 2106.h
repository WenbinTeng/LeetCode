#include <vector>
#include <algorithm>

class Solution {
public:
    int maxTotalFruits(std::vector<std::vector<int>>& fruits, int startPos, int k) {
        int res = 0;
        
        std::vector<int> sum;
        sum.push_back(0);
        for (int i = 0; i < fruits.size(); ++i)
            sum.push_back(fruits[i][1] + sum[i]);

        std::vector<int> pos;
        for (int i = 0; i < fruits.size(); ++i)
            pos.push_back(fruits[i][0]);

        for (int x = k; x >= 0; --x)
        {
            int y = (k - x) / 2;
            int l;
            int r;
            
            l = startPos - x, r = startPos + y;
            auto pl = std::lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            auto pr = std::upper_bound(pos.begin(), pos.end(), r) - pos.begin();
            res = std::max(res, sum[pr] - sum[pl]);
            
            l = startPos - y, r = startPos + x;
            pl = std::lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            pr = std::upper_bound(pos.begin(), pos.end(), r) - pos.begin();
            res = std::max(res, sum[pr] - sum[pl]);
        }
        
        return res;
    }
};