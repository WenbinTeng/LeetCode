#include <algorithm>
#include <stack>
#include <string>

class Solution {
public:
    bool canChange(std::string &start, std::string &target) {
        std::string s = start;
        std::string t = target;

        s.erase(std::remove(s.begin(), s.end(), '_'), s.end());
        t.erase(std::remove(t.begin(), t.end(), '_'), t.end());
        if (s != t)
            return false;

        for (int i = 0, j = 0; i < start.length(); ++i) {
            if (start[i] == '_')
                continue;
            while (target[j] == '_')
                ++j;
            if (i != j && (start[i] == 'L') == (i < j))
                return false;
            ++j;
        }

        return true;
    }
};