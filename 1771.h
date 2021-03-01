#include <vector>
#include <string>

class Solution {
public:
    int longestPalindrome(std::string word1, std::string word2) {
        std::string word = word1 + word2;
        int n1 = word1.size();
        int n2 = word2.size();
        std::vector<std::vector<int>> dp(n1 + n2, std::vector<int>(n1 + n2, 0));
        int res = word1.back() == word2.front() ? 2 : 0;

        for (int i = 0; i < n1 + n2; ++i) dp[i][i] = 1;
        
        for (int i = 0; i < n1 + n2 - 1; ++i) dp[i][i + 1] = word[i] == word[i + 1] ? 2 : 1;

        for (int k = 2; k < n1 + n2; ++k)
        {
            for (int i = 0, j = k; j < n1 + n2; ++i, ++j)
            {
                if (word[i] == word[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
                }

                res = word[i] == word[j] && i < n1 && j >= n1 ? std::max(res, dp[i][j]) : res;
            }
        }

        return res;
    }
};