#include <string>
#include <cctype>

class Solution {
public:
    bool detectCapitalUse(std::string word) {
        bool allLower = true;
        bool allUpper = true;

        for (int i = 1; i < word.size(); i++) {
            if (std::isupper(word[i])) {
                allLower = false;
                break;
            }
        }

        for (int i = 1; i < word.size(); i++) {
            if (std::islower(word[i])) {
                allUpper = false;
                break;
            }
        }

        return allLower || std::isupper(word[0]) && allUpper;
    }
};