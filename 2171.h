#include <algorithm>
#include <vector>

class Solution {
public:
    long long minimumRemoval(std::vector<int> &beans) {
        long long res = LLONG_MAX;
        long long sum1 = 0;
        long long sum2 = 0;

        for (const auto bean : beans) {
            sum2 += bean;
        }

        std::sort(beans.begin(), beans.end());

        for (int i = 0; i < beans.size(); ++i) {
            res = std::min(res, sum1 + sum2 - beans[i] * ((long long)beans.size() - i));
            sum1 += beans[i];
            sum2 -= beans[i];
        }

        res = std::min(res, sum1);

        return res;
    }
};