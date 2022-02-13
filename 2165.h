#include <vector>
#include <algorithm>

class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;

        long long res = 0;
        long long abs = std::abs(num);
        std::vector<int> digits;

        while (abs)
        {
            digits.push_back(abs % 10);
            abs /= 10;
        }

        if (num < 0)
        {
            std::sort(digits.begin(), digits.end(), std::greater<int>());
        }
        else
        {
            std::sort(digits.begin(), digits.end(), std::less<int>());
        }

        if (digits[0] == 0)
        {
            for (int i = 0; i < digits.size(); ++i)
            {
                if (digits[i] != 0)
                {
                    std::swap(digits[0], digits[i]);
                    break;
                }
            }
        }

        for (const auto digit : digits)
        {
            res *= 10;
            res += digit;
        }

        return num < 0 ? -res : res;
    }
};