#include <string>
#include <algorithm>

class Solution {
public:
    std::string reverseParentheses(std::string s) {
        int index = 0;
        return reverseSubStr(s, index);
    }

private:
    std::string reverseSubStr(std::string& s, int& index)
    {
        std::string substr = "";

        for (; index < s.size(); ++index)
        {
            if (s[index] == '(')
            {
                ++index;
                substr += reverseSubStr(s, index);
            }
            else if (s[index] == ')')
            {
                std::reverse(substr.begin(), substr.end());
                return substr;
            }
            else
            {
                substr.push_back(s[index]);
            }
        }

        return substr;
    }
};