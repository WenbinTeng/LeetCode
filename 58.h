#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int res = 0;

        while (!s.empty() && s.back() == ' ')
            s.pop_back();

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ')
                break;
            res++;
        }

        return res;
    }
};