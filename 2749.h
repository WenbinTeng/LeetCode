#include <algorithm>

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num1 == 0)
            return 0;
        
        long long n1 = num1;
        long long n2 = num2;
        for (int i = 0; i <= 60; i++) {
            auto [lower, upper] = countOnes(n1);
            if ((lower <= i) && (upper == 0) && (n1 >= i))
                return i;
            n1 -= n2;
        }
        return -1;
    }

private:
    std::pair<int, int> countOnes(long long num) {
        int lower = 0;
        int upper = 0;
        for (int i = 0; i < 60; i++) {
            lower += (num & 1);
            num = (unsigned long long)num >> 1;
        }
        while (num) {
            upper += (num & 1);
            num = (unsigned long long)num >> 1;
        }
        return {lower, upper};
    }
};