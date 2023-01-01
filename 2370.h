#include <string>
#include <vector>

class Solution {
public:
    int longestIdealString(std::string s, int k) {
        int res = 0;
        std::vector<int> dp(26, 0);

        for (const auto c : s) {
            int len = 0;

            for (int i = 0; i < 26; ++i) {
                if (std::abs(c - 'a' - i) <= k) {
                    len = std::max(len, dp[i] + 1);
                }
            }

            dp[c - 'a'] = len;
        }

        for (int i = 0; i < 26; ++i) {
            res = std::max(res, dp[i]);
        }

        return res;
    }
};