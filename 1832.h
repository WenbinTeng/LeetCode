#include <string>
#include <unordered_set>

class Solution {
public:
    bool checkIfPangram(std::string sentence) {
        std::unordered_set<char> us;

        for (char i = 'a'; i <= 'z'; ++i)
            us.insert(i);

        for (const auto &c : sentence) {
            if (us.find(c) != us.end())
                us.erase(c);
            if (us.empty())
                return true;
        }

        return false;
    }
};