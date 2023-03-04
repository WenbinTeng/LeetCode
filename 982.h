#include <vector>

class Solution {
public:
    int countTriplets(std::vector<int> &nums) {
        int res = 0;
        std::vector<int> cnt(1 << 16);

        for (int x : nums) {
            for (int y : nums) {
                ++cnt[x & y];
            }
        }

        for (int x : nums) {
            for (int mask = 0; mask < (1 << 16); ++mask) {
                if ((x & mask) == 0) {
                    res += cnt[mask];
                }
            }
        }

        return res;
    }
};