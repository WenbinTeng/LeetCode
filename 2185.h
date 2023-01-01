#include <string>
#include <vector>

class Solution {
public:
    int prefixCount(std::vector<std::string> &words, std::string pref) {
        int res = 0;

        for (auto &word : words) {
            if (isPrefix(word, pref))
                ++res;
        }

        return res;
    }

private:
    bool isPrefix(std::string &s, std::string &p) {
        if (p.size() > s.size())
            return false;

        for (int i = 0; i < p.size(); ++i) {
            if (s[i] != p[i])
                return false;
        }

        return true;
    }
};