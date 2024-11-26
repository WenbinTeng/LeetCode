#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minArraySum(std::vector<int>& nums, int K, int op1, int op2) {
        const int inf = 1e+9;
        int res = inf;
        int n = nums.size();
        std::vector<std::vector<std::vector<int>>> dp(n + 1, std::vector<std::vector<int>>(op1 + 1, std::vector<int>(op2 + 1, inf)));

        dp[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= op1; j++) {
                for (int k = 0; k <= op2; k++) {
                    dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][j][k] + nums[i - 1]);
                    if (j > 0)
                        dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][j - 1][k] + (nums[i - 1] + 1) / 2);
                    if (k > 0 && nums[i - 1] >= K)
                        dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][j][k - 1] + nums[i - 1] - K);
                    if (j > 0 && k > 0) {
                        int x = (nums[i - 1] + 1) / 2;
                        int y = nums[i - 1] - K;
                        if (x >= K)
                            dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][j - 1][k - 1] + x - K);
                        if (y >= 0)
                            dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][j - 1][k - 1] +(y + 1) / 2);
                    }
                }
            }
        }

        for (int j = 0; j <= op1; j++) {
            for (int k = 0; k <= op2; k++) {
                res = std::min(res, dp[n][j][k]);
            }
        }

        return res;
    }
};