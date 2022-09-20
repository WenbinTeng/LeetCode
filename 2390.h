#include <string>

class Solution {
public:
    std::string removeStars(std::string s) {
        std::string res;

        for (auto c : s)
        {
            if (c == '*')
            {
                if (!res.empty()) res.pop_back();
            }
            else
            {
                res.push_back(c);
            }
        }

        return res;
    }
};