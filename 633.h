#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0;
        int r = (int)std::sqrt(c) + 1;

        while (l <= r)
        {
            long long res = l * l + r * r;

            if (res == c) return true;
            else if (res < c) --l;
            else if (res > c) --r;
        }

        return false;
    }
};