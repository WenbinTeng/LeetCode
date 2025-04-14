#include <string>
#include <algorithm>

class Solution {
public:
    std::string smallestPalindrome(std::string s) {
        if (s.size() == 1)
            return s;

        int n = s.size();
        std::string res;

        std::string half = s.substr(0, n / 2);
        std::sort(half.begin(), half.end());

        std::string halfRev(half);
        std::reverse(halfRev.begin(), halfRev.end());
        
        if (n % 2 == 0)
            res = half + halfRev;
        else
            res = half + s[n / 2] + halfRev;
        
        return res;
    }
};