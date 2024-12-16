#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int makeStringGood(std::string s) {
        std::vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        int max = *std::max_element(cnt.begin(), cnt.end());
        int res = s.length();
        int dp[27]{};

        for (int target = 1; target <= max; target++) {
            dp[25] = std::min(cnt[25], std::abs(cnt[25] - target));
            for (int i = 24; i >= 0; i--) {
                int x = cnt[i];
                int y = cnt[i + 1];
                dp[i] = dp[i + 1] + std::min(x, abs(x - target));
                if (y < target) {
                    int t = x > target ? target : 0;
                    dp[i] = std::min(dp[i], dp[i + 2] + std::max(x - t, target - y));
                }
            }
            res = std::min(res, dp[0]);
        }

        return res;
    }
};