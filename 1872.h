#include <vector>

class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        for(int i = 1; i < stones.size(); ++i) stones[i] += stones[i-1];

        int res = 0;
        int rec = -__INT_MAX__ - 1;

        for(int i = stones.size() - 1; i >= 1; --i) {
            rec = std::max(rec, stones[i] - res);
            res = rec;
        }
        
        return res;
    }
};