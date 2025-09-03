#include <algorithm>
#include <queue>
#include <string>
#include <vector>

class Solution {
  public:
    bool canReach(std::string s, int minJump, int maxJump) {
        int vis = 0;
        std::vector<bool> dp(s.size(), false);

        dp[0] = true;

        for (int i = 0; i < s.size(); ++i) {
            if (!dp[i])
                continue;

            for (int j = std::max(vis - i, minJump); j <= maxJump; ++j) {
                if (i + j >= s.size())
                    break;

                dp[i + j] = s[i + j] == '0';
            }

            vis = std::max(vis, i + maxJump);
        }

        return dp.back() && s.back() == '0';
    }
};