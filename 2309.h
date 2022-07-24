#include <string>
#include <unordered_set>

class Solution {
public:
    std::string greatestLetter(std::string s) {
        std::string res;
        std::unordered_set<char> us;

        for (const auto c : s)
        {
            us.insert(c);
        }

        for (char c = 'Z'; c >= 'A'; --c)
        {
            if (us.count(c) && us.count(c - 'A' + 'a'))
            {
                res.push_back(c);
                return res;
            }
        }

        return "";
    }
};