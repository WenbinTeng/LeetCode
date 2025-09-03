#include <cmath>

class Solution {
  public:
    int countTriples(int n) {
        int res = 0;

        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int squreSum = a * a + b * b;
                int c = std::sqrt(squreSum);
                if (c * c == squreSum && c <= n)
                    res++;
            }
        }

        return res;
    }
};