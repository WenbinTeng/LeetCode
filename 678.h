#include <string>
#include <vector>

class Solution {
public:
    bool checkValidString(std::string s) {

        if (s.size() <= 0)
            return false;
        if (s.size() == 1)
            return s == "*";
        if (s.size() == 2)
            return s == "()" || s == "(*" || s == "*)" || s == "**";

        int n = s.size();
        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));

        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                dp[i][i] = true;
            }
        }

        for (int i = 1; i < n; ++i) {
            if ((s[i - 1] == '(' || s[i - 1] == '*') && (s[i] == '*' || s[i] == ')')) {
                dp[i - 1][i] = true;
            }
        }

        for (int i = n - 3; i >= 0; --i) {
            for (int j = i + 2; j < n; ++j) {
                if ((s[i] == '(' || s[i] == '*') && (s[j] == '*' || s[j] == ')')) {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                for (int k = i; k < j && !dp[i][j]; ++k) {
                    dp[i][j] = dp[i][k] && dp[k + 1][j];
                }
            }
        }

        return dp[0][n - 1];
    }
};