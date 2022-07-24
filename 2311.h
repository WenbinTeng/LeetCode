#include <vector>
#include <string>

class Solution {
public:
    int longestSubsequence(std::string s, int k) {
        int cnt = 0;
        unsigned int digits = 0;

        for (const auto c : s)
        {
            if (c == '0') ++cnt;
        }

        for (int i = 0; i < s.size() && i < 32; ++i)
        {
            if (s[s.size() - 1 - i] == '1')
            {
                digits |= (1 << i);

                if (digits > k)
                {
                    return cnt;
                }
                else
                {
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};