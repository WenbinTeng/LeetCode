#include <string>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> rec;
        std::vector<std::vector<bool>> dp(s.size(),
                                          std::vector<bool>(s.size(), false));

        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[j][i] = i == j || i == j + 1
                               ? s[i] == s[j]
                               : s[i] == s[j] && dp[j + 1][i - 1];
            }
        }

        dfs(s, res, rec, dp, 0);

        return res;
    }

  private:
    void dfs(std::string &s, std::vector<std::vector<std::string>> &res,
             std::vector<std::string> &rec, std::vector<std::vector<bool>> &dp,
             int index) {
        if (index == s.size()) {
            res.push_back(rec);
            return;
        }

        for (int i = index; i < s.size(); ++i) {
            if (dp[index][i]) {
                rec.push_back(s.substr(index, i - index + 1));
                dfs(s, res, rec, dp, i + 1);
                rec.pop_back();
            }
        }
    }
};