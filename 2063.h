#include <string>

class Solution {
public:
    long long countVowels(std::string word) {
        long long res = 0;

        for (int i = 0; i < word.size(); ++i) {
            switch (word[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                res += (i + 1) * (word.size() - i);
                break;
            default:
                break;
            }
        }

        return res;
    }
};