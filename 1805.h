#include <string>
#include <unordered_set>

class Solution {
public:
    int numDifferentIntegers(std::string word) {
        std::unordered_set<std::string> us;

        int l = 0;
        int r = 0;

        while (r < word.size()) {
            if (word[r] >= '0' && word[r] <= '9')
                ++r;
            else {
                if (l < r) {
                    while (word[l] == '0') {
                        ++l;
                    }
                    us.insert(word.substr(l, r - l));
                }

                l = ++r;
            }
        }

        if (l < r) {
            while (word[l] == '0') {
                ++l;
            }
            us.insert(word.substr(l, r - l + 1));
        }

        return us.size();
    }
};