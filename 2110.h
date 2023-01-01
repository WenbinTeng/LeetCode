#include <vector>

class Solution {
public:
    long long getDescentPeriods(std::vector<int> &prices) {
        long long res = prices.size();

        int l = 0;
        int r = 1;

        while (r < prices.size()) {
            if (prices[r - 1] - prices[r] == 1) {
                ++r;
            } else {
                long long len = r - l;
                res += len * (len - 1) / 2;
                l = r;
                ++r;
            }
        }

        if (l < r && r > 1) {
            long long len = r - l;
            res += len * (len - 1) / 2;
            l = r;
        }

        return res;
    }
};