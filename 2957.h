#include <string>

class Solution {
public:
    int removeAlmostEqualCharacters(std::string word) {
        int res = 0;

        for (int i = 0; i < word.size() - 1; i++) {
            if (std::abs(word[i] - word[i + 1]) <= 1) {
                res++;
                i++;
            }
        }

        return res;
    }
};