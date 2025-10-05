#include <string>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
        const int n = s.size();
        std::unordered_set<std::string> dict;
        std::vector<int> dp(n + 1, 0);

        for (auto word : wordDict) {
            dict.insert(word);
        }

        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[n];
    }
};