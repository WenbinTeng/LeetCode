#include <string>

class Solution {
public:
    int equalSubstring(std::string s, std::string t, int maxCost) {
        int l = 0;
        int r = 0;
        int sumCost = 0;

        while (r < s.size()) {
            sumCost += std::abs(s[r] - t[r]);
            if (sumCost > maxCost) {
                sumCost -= std::abs(s[l] - t[l]);
                l++;
            }
            r++;
        }

        return r - l;
    }
};