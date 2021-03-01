#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        
        for (int i = 0; i < s.size(); i++)
        {
            checkExpand(s, i, i + 0);
            checkExpand(s, i, i + 1);
        }

        return subString;
    }

private:
    std::string subString = "";

    void checkExpand(std::string& s, int i, int j)
    {
        while (i >= 0 && j < s.size())
        {
            if (s[i] == s[j])
            {
                i--;
                j++;
            }
            else
                break;
        }
        if (subString.size() < j - i - 1)
        {
            subString = s.substr(i + 1, j - i - 1);
        }
    }
};