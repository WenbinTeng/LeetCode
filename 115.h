#include <vector>
#include <string>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        std::vector<std::vector<long long>> dp(s.size() + 1, std::vector<long long>(t.size() + 1));
        for (int i = 0; i < s.size(); ++i) dp[i][0] = 1;
        for (int i = 1; i < t.size(); ++i) dp[0][i] = 0;

        for (int i = 1; i < s.size() + 1; ++i)
        {
            for (int j = 1; j < t.size() + 1; ++j)
            {
                dp[i][j] = s[i - 1] == t[j - 1] ? dp[i - 1][j] + dp[i - 1][j - 1] : dp[i - 1][j];
            }
        }

        return (int)dp[s.size()][t.size()];
    }
};