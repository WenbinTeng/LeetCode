#include <set>
#include <string>

class Solution {
public:
    int longestBeautifulSubstring(std::string word) {
        int res = 0;
        int l = 0;
        int r = 0;

        std::set<char> s{'a', 'e', 'i', 'o', 'u'};

        while (r < word.size()) {
            if (r > 0 && word[r - 1] > word[r]) {
                s = std::set<char>{'a', 'e', 'i', 'o', 'u'};
                l = r;
            }

            s.erase(word[r]);
            if (s.empty())
                res = std::max(res, r - l + 1);
            ++r;
        }

        if (s.empty())
            res = std::max(res, r - l);

        return res;
    }
};