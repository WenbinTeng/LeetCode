#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string largestPalindromic(std::string num) {
        std::string res;
        std::string rev;
        std::vector<int> cnt(10);

        for (const auto digit : num)
        {
            ++cnt[digit - '0'];
        }
        
        for (int i = 9; i >= 0; --i)
        {
            if (i == 0 && rev.empty()) continue;

            while (cnt[i] >= 2)
            {
                rev.push_back(i + '0');
                cnt[i] -= 2;
            }
        }

        for (int i = 9; i >= 0; --i)
        {
            if (cnt[i])
            {
                res = rev;
                std::reverse(rev.begin(), rev.end());
                return res + std::to_string(i) + rev;
            }
        }

        res = rev;
        std::reverse(rev.begin(), rev.end());
        return res + rev;
    }
};