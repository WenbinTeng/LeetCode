#include <vector>
#include <string>

class Solution {
public:
    int minCut(std::string s) {
        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));
        std::vector<int> f(s.size(), INT_MAX);

        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                dp[j][i] = i == j || i == j + 1 ? s[i] == s[j] : s[i] == s[j] && dp[j + 1][i - 1];
            }
        }

        for (int i = 0; i < s.size(); ++i)
        {
            if (dp[0][i]) {f[i] = 0; continue;}

            for (int j = 0; j < i; ++j)
            {
                if (dp[j + 1][i])
                {
                    f[i] = std::min(f[i], f[j] + 1);
                }
            }
        }

        return f.back();
    }
};