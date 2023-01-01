#include <vector>

class Solution {
public:
    int largestCombination(std::vector<int> &candidates) {
        int res = 0;
        std::vector<int> cnt(32);

        for (const auto candidate : candidates) {
            for (int i = 0; i < 32; ++i) {
                if (candidate & (1 << i)) {
                    ++cnt[i];
                }
            }
        }

        for (int i = 0; i < 32; ++i) {
            res = std::max(res, cnt[i]);
        }

        return res;
    }
};