#include <cmath>

class Solution {
public:
    int pivotInteger(int n) {
        int m = (n + 1) * n / 2;
        int x = std::sqrt(m);
        return x * x == m ? x : -1;
    }
};