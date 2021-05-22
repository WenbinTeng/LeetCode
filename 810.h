#include <vector>
#include <numeric>

class Solution {
public:
    bool xorGame(std::vector<int>& nums) {
        return nums.size() % 2 == 0 || !std::accumulate(nums.begin(), nums.end(), 0, [](int x, int y) { return x ^ y; });
    }
};