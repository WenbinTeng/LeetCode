#include <vector>

class Solution {
public:
    int arraySign(std::vector<int> &nums) {
        int cnt;

        for (const auto &num : nums) {
            if (num == 0)
                return 0;
            else if (num < 0)
                ++cnt;
        }

        return cnt & 1 ? -1 : 1;
    }
};