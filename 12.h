#include <string>

class Solution {
public:
    std::string intToRoman(int num) {
        const char *alphabet[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}};

        return std::string(alphabet[3][num / 1000]) +
               std::string(alphabet[2][num / 100 % 10]) +
               std::string(alphabet[1][num / 10 % 10]) +
               std::string(alphabet[0][num % 10]);
    }
};