#include <algorithm>

class Solution {
public:
    int commonFactors(int a, int b) {
        int res = 0;

        for (int i = 1, n = std::min(a, b); i <= n; ++i) {
            if (a % i == 0 && b % i == 0) {
                ++res;
            }
        }

        return res;
    }
};