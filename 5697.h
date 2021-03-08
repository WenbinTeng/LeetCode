#include <string>

class Solution {
public:
    bool checkOnesSegment(std::string s) {
        bool flag = true;

        int index = 0;

        while (index < s.size())
        {
            if (s[index++] == '0') break;
        }

        while (index < s.size())
        {
            if (s[index++] == '1')
            {
                flag = false; break;
            }
        }

        return flag;
    }
};