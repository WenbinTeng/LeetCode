#include <string>
#include <vector>

class Solution {
  public:
    int numberOfCombinations(std::string num) {
        if (num[0] == '0') {
            return 0;
        }

        const int mod = 1e+9 + 7;
        int n = num.size();

        std::vector<std::vector<int>> lcp(n, std::vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            lcp[i][n - 1] = (num[i] == num[n - 1]);
            for (int j = i + 1; j < n - 1; ++j) {
                lcp[i][j] = (num[i] == num[j] ? lcp[i + 1][j + 1] + 1 : 0);
            }
        }

        auto update = [&](int &x, int y) {
            x += y;
            if (x >= mod) {
                x -= mod;
            }
        };

        std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            if (num[i] == '0') {
                continue;
            }
            int presum = 0;
            for (int j = i; j < n; ++j) {
                int length = j - i + 1;
                dp[i][j] = presum;
                if (i - length >= 0) {
                    if (lcp[i - length][i] >= length ||
                        num[i - length + lcp[i - length][i]] <
                            num[i + lcp[i - length][i]]) {
                        update(dp[i][j], dp[i - length][i - 1]);
                    }
                    update(presum, dp[i - length][i - 1]);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            update(res, dp[i][n - 1]);
        }
        return res;
    }
};