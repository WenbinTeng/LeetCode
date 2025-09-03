#include <string>

class Solution {
  public:
    bool splitString(std::string s) {
        for (int i = 0; i < s.size() - 1; ++i) {
            if (dfs(s, i + 1, std::stoull(s.substr(0, i + 1))))
                return true;
        }

        return false;
    }

  private:
    bool dfs(std::string &s, int index, unsigned long long prevVal) {
        if (index == s.size())
            return true;

        for (int i = index; i < s.size(); ++i) {
            unsigned long long currVal =
                std::stoull(s.substr(index, i - index + 1));
            if (prevVal - currVal != 1)
                continue;
            if (dfs(s, i + 1, currVal))
                return true;
        }

        return false;
    }
};