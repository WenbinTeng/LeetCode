#include <string>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int res = 0;
        int mostCount = 0;
        int charCount[26] = {0};
        int l;
        int r;

        for (l = 0, r = 0; r < s.size(); r++) {
            mostCount = std::max(mostCount, ++charCount[s[r] - 'A']);

            if (r - l + 1 - mostCount > k) {
                charCount[s[l++] - 'A']--;
            }
        }

        return r - l;
    }
};