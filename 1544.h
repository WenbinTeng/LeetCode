#include <string>

class Solution {
public:
    std::string makeGood(std::string s) {
        if (s.empty())
            return "";

        std::string res;
        for (const auto &c : s) {
            if (!res.empty()) {
                if (c >= 'A' && c <= 'Z' && c - res.back() == 'A' - 'a') {
                    res.pop_back();
                    continue;
                }
                if (c >= 'a' && c <= 'z' && c - res.back() == 'a' - 'A') {
                    res.pop_back();
                    continue;
                }

                res.push_back(c);
            } else {
                res.push_back(c);
            }
        }

        return res;
    }
};