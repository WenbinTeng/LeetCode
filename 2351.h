#include <string>
#include <unordered_set>

class Solution {
public:
    char repeatedCharacter(std::string s) {
        std::unordered_set<char> us;

        for (const auto c : s)
        {
            if (us.count(c))
            {
                return c;
            }
            else
            {
                us.insert(c);
            }
        }

        return 0;
    }
};