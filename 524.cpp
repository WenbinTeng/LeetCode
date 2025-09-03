#include <algorithm>
#include <string>
#include <vector>

class Solution {
  public:
    std::string findLongestWord(std::string s,
                                std::vector<std::string> &dictionary) {
        std::sort(dictionary.begin(), dictionary.end(),
                  [](std::string &s1, std::string &s2) {
                      return s1.size() == s2.size() ? s1 < s2
                                                    : s1.size() > s2.size();
                  });

        for (const auto word : dictionary) {
            if (isMatch(s, word))
                return word;
        }

        return "";
    }

  private:
    bool isMatch(const std::string &s, const std::string &w) {
        int i = 0;
        int j = 0;

        while (i < s.size() && j < w.size()) {
            if (s[i] == w[j])
                ++j;
            ++i;
        }

        return j == w.size();
    }
};