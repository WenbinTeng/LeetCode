#include <algorithm>
#include <vector>

class Solution {
  public:
    int getMaximumConsecutive(std::vector<int> &coins) {
        int res = 1;

        std::sort(coins.begin(), coins.end());

        for (const auto coin : coins) {
            if (coin > res)
                break;
            res += coin;
        }

        return res;
    }
};