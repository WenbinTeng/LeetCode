#include <string>

class Solution {
public:
    bool hasSameDigits(std::string s) {
        std::string buff;

        while (s.size() > 2) {
            int top = s.back() - '0';
            s.pop_back();
            while (!s.empty()) {
                int sum = (top + (int)(s.back() - '0')) % 10;
                buff.push_back(sum + '0');
                top = s.back() - '0';
                s.pop_back();
            }
            s = buff;
            buff.clear();
        }

        return s[0] == s[1];
    }
};