#include <string>

class Solution {
public:
    bool checkPalindromeFormation(std::string a, std::string b) {
        return checkPalindrome(a, b) || checkPalindrome(b, a);
    }

private:
    bool checkPalindrome(std::string &a, std::string &b) {
        int l = 0;
        int r = a.size() - 1;
        while (l < r && a[l] == b[r]) {
            l++;
            r--;
        }
        return isPalindrome(a, l, r) || isPalindrome(b, l, r);
    }

    bool isPalindrome(std::string &s, int l, int r) {
        while (l < r && s[l] == s[r]) {
            l++;
            r--;
        }
        return l >= r;
    }
};