#include <string>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
        auto dp = std::vector<bool>(s.size() + 1);
        auto wordDictSet = std::unordered_set<std::string>();

        for (const auto word : wordDict) {
            wordDictSet.insert(word);
        }

        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] &&
                    wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};