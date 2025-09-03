#include <string>
#include <vector>

class Solution {
  public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int n = text1.size();
        int m = text2.size();
        int res = 0;

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j + 1]);
                }
                res = std::max(res, dp[i + 1][j + 1]);
            }
        }

        return res;
    }
};