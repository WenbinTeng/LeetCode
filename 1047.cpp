#include <string>

class Solution {
  public:
    std::string removeDuplicates(std::string S) {
        if (S.empty())
            return "";

        std::string res = "";

        for (const auto &c : S) {
            !res.empty() && res.back() == c ? res.pop_back() : res.push_back(c);
        }

        return res;
    }
};