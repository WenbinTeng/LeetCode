#include <string>

class Solution {
public:
    int maxScore(std::string s) {
        int res = 0;
        int cnt = 0;

        for (const auto c : s) {
            if (c == '1') {
                ++cnt;
            }
        }

        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') {
                ++cnt;
            } else {
                --cnt;
            }
            res = std::max(res, cnt);
        }

        return res;
    }
};