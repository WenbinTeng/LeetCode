#include <string>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    int minSteps(std::string s, std::string t) {
        int res = 0;
        std::unordered_set<char> us;
        std::unordered_map<char, int> ums;
        std::unordered_map<char, int> umt;

        for (const auto& c : s)
        {
            ++ums[c];
            us.insert(c);
        }

        for (const auto& c : t)
        {
            ++umt[c];
            us.insert(c);
        }

        for (const auto& c : us)
        {
            res += std::abs(ums[c] - umt[c]);
        }

        return res;
    }
};