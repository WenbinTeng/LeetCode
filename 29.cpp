#include <cstdlib>

class Solution {
  public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (divisor == +1)
            return +dividend;
        if (divisor == -1)
            return -dividend;
        bool sign = dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0;
        dividend = -std::abs(dividend);
        divisor = -std::abs(divisor);
        int res = generate(dividend, divisor);
        return sign ? -res : res;
    }

  private:
    int generate(int dividend, int divisor) {
        if (dividend > divisor)
            return 0;

        int divTime = 1;
        int divNext = divisor;

        while (divNext - dividend + divNext >= 0) {
            divTime = divTime + divTime;
            divNext = divNext + divNext;
        }

        return divTime + generate(dividend - divNext, divisor);
    }
};