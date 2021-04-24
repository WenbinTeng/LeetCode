#include <vector>
#include <algorithm>

class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins) {
        int res = 0;

        std::sort(costs.begin(), costs.end());

        for (const auto cost : costs)
        {
            if (coins < cost) break;
            coins -= cost;
            ++res;
        }

        return res;
    }
};