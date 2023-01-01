#include <string>
#include <vector>

class Solution {
public:
    std::string firstPalindrome(std::vector<std::string> &words) {
        for (auto &word : words) {
            if (isPalindrome(word))
                return word;
        }
        return "";
    }

private:
    bool isPalindrome(std::string &s) {
        int l = 0;
        int r = s.size() - 1;

        while (l <= r) {
            if (s[l] != s[r])
                return false;
            ++l;
            --r;
        }

        return true;
    }
};