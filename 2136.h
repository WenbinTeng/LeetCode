#include <algorithm>
#include <vector>

class Solution {
public:
    int earliestFullBloom(std::vector<int> &plantTime, std::vector<int> &growTime) {
        int res = 0;
        int day = 0;
        std::vector<int> order(plantTime.size());

        for (int i = 0; i < plantTime.size(); ++i) {
            order[i] = i;
        }

        std::sort(order.begin(), order.end(), [&](int i, int j) { return growTime[i] > growTime[j]; });

        for (int i = 0; i < order.size(); ++i) {
            day += plantTime[order[i]];
            res = std::max(res, day + growTime[order[i]]);
        }

        return res;
    }
};