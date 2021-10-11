#include <vector>

class Solution {
public:
    bool stoneGameIX(std::vector<int>& stones) {
        int s[3] = {0, 0, 0};

        for (const auto& i : stones) ++s[i % 3];

        return s[0] % 2 == 0 ? s[1] != 0 && s[2] != 0 : s[2] > s[1] + 2 || s[1] > s[2] + 2;
    }
};