#include <algorithm>
#include <vector>

class Solution {
public:
    int findContentChildren(std::vector<int> &g, std::vector<int> &s) {
        int res = 0;
        int gp = 0;
        int sp = 0;

        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        while (sp < s.size() && s[sp] < g[0])
            ++sp;

        while (sp < s.size() && gp < g.size()) {
            if (s[sp] >= g[gp]) {
                ++sp;
                ++gp;
                ++res;
            } else {
                ++sp;
            }
        }

        return res;
    }
};