#include <vector>
#include <functional>
#include <algorithm>

class Solution {
public:
    int maxCoins(std::vector<int>& piles) {
        int n = piles.size() / 3;
        int res = 0;

        std::sort(piles.begin(), piles.end(), std::greater<int>());

        for (int i = 0; i < n; i++) {
            res += piles[i * 2 + 1];
        }

        return res;
    }
};