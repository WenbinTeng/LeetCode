#include <string>

class Solution {
public:
    bool checkString(std::string s) {
        bool flag = false;

        for (int i = 0; i < s.size(); ++i) {
            if (flag) {
                if (s[i] == 'a')
                    return false;
            } else {
                if (s[i] == 'b')
                    flag = true;
            }
        }

        return true;
    }
};