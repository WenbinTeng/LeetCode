#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    std::vector<std::string> wordBreak(std::string s,
                                       std::vector<std::string> &wordDict) {
        wordSet = std::unordered_set(wordDict.begin(), wordDict.end());
        backtrack(s, 0);
        return res[0];
    }

  private:
    std::unordered_map<int, std::vector<std::string>> res;
    std::unordered_set<std::string> wordSet;

    void backtrack(const std::string &s, int index) {
        if (!res.count(index)) {
            if (index == s.size()) {
                res[index] = {""};
                return;
            }
            res[index] = {};
            for (int i = index + 1; i <= s.size(); ++i) {
                auto word = s.substr(index, i - index);
                if (wordSet.count(word)) {
                    backtrack(s, i);
                    for (const auto &t : res[i]) {
                        res[index].push_back(t.empty() ? word : word + " " + t);
                    }
                }
            }
        }
    }
};