#include <string>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1));

        for (int i1 = 0; i1 <= text1.size(); ++i1) {
            for (int i2 = 0; i2 <= text2.size(); ++i2) {
                if (i1 == 0) {
                    dp[i1][i2] = 0;
                    continue;
                }
                if (i2 == 0) {
                    dp[i1][i2] = 0;
                    continue;
                }

                if (text1[i1 - 1] == text2[i2 - 1]) {
                    dp[i1][i2] = dp[i1 - 1][i2 - 1] + 1;
                } else {
                    dp[i1][i2] = std::max(dp[i1 - 1][i2], dp[i1][i2 - 1]);
                }
            }
        }

        return dp.back().back();
    }
};