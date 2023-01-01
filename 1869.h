#include <string>

class Solution {
public:
    bool checkZeroOnes(std::string s) {
        int zero = 0;
        int ones = 0;
        int cnt = 0;

        for (const auto &c : s) {
            if (c == '0')
                ++cnt;
            else
                cnt = 0;
            zero = std::max(zero, cnt);
        }

        cnt = 0;

        for (const auto &c : s) {
            if (c == '1')
                ++cnt;
            else
                cnt = 0;
            ones = std::max(ones, cnt);
        }

        return ones > zero;
    }
};