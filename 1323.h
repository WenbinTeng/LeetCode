#include <vector>

class Solution {
public:
    int maximum69Number (int num) {
        std::vector<int> factors = {10000, 1000, 100, 10, 1};

        for (int i = 0; i < 4; i++) {
            int digit = (num % factors[i]) / factors[i + 1];
            if (digit == 6) {
                return num + factors[i + 1] * 3;
            }
        }

        return num;
    }
};