#include <cstdlib>

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (n == INT_MIN) {
            double y = quickPow(x, -(n / 2));
            return 1.0 / y / y;
        }
        if (n > 0)
            return quickPow(x, +n) / 1.0;
        if (n < 0)
            return 1.0 / quickPow(x, -n);

        return 0;
    }

private:
    double quickPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        } else {
            double y = quickPow(x, n / 2);
            return n % 2 == 0 ? y * y : y * y * x;
        }
    }
};