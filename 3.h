#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (!s.size()) return 0;

        int flag[256] = {0};
        int head = 0;
        int tail = 0;
        int maxLen = 1;
        int stringSize = s.size();

        flag[s[0]] = 1;
        while (tail++ < stringSize)
        {
            if (flag[s[tail]])
            {
                maxLen = std::max(maxLen, tail - head);
                while (head < flag[s[tail]])
                {
                    flag[s[head++]] = 0;
                }
            }
            flag[s[tail]] = tail + 1;
        }
        maxLen = std::max(maxLen, tail - head - 1);

        return maxLen;
    }
};