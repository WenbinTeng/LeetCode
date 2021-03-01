#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string res;
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());

        int carry = 0;
        for (int i = 0, n = std::max(a.size(), b.size()); i < n; ++i) {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            res.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }
        if (carry) res.push_back('1');

        reverse(res.begin(), res.end());

        return res;
    }
};