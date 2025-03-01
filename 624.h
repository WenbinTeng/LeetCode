#include <vector>

class Solution {
public:
    int maxDistance(std::vector<std::vector<int>>& arrays) {
        int ans = 0;
        int min = INT_MAX / 2;
        int max = INT_MIN / 2;

        for (auto& a : arrays) {
            ans = std::max({ans, a.back() - min, max - a.front()});
            min = std::min(min, a.front());
            max = std::max(max, a.back());
        }

        return ans;
    }
};