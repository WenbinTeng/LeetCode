#include <vector>
#include <string>

class Solution {
public:
    bool isScramble(std::string s1, std::string s2) {
        if (s1.empty() || s2.empty() || s1.size() != s2.size()) return false;

        int n1 = s1.size();
        int n2 = s2.size();

        if (s1 == s2) return true;

        std::vector<int> rec(26);
        for (int i = 0; i < s1.size() && i < s2.size(); ++i)
        {
            ++rec[s1[i] - 'a'];
            --rec[s2[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i)
        {
            if (rec[i] != 0) return false;
        }

        for (int i = 0; i < s1.size() && i < s2.size(); ++i)
        {
            if (isScramble(s1.substr(0, i), s2.substr(0,       i)) && isScramble(s1.substr(i, n1), s2.substr(i,     n2))) return true;
            if (isScramble(s1.substr(0, i), s2.substr(n2 - i, n2)) && isScramble(s1.substr(i, n1), s2.substr(0, n2 - i))) return true;
        }

        return false;
    }
};