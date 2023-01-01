#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        return generate("1", 1, n);
    }

private:
    std::string generate(std::string s, int i, int n) {
        if (i == n)
            return s;

        std::string res = "";
        int index = 0;
        while (index < s.size()) {
            char digit = s[index], count = '0';
            while (index < s.size() && digit == s[index]) {
                index++;
                count++;
            }
            res += count;
            res += digit;
        }

        return generate(res, i + 1, n);
    }
};