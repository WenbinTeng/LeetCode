#include <string>
#include <vector>

class Solution {
  public:
    bool isPrefixString(std::string s, std::vector<std::string> &words) {
        int index = 0;

        for (const auto word : words) {
            for (const auto c : word) {
                if (index == s.size()) {
                    return false;
                }
                if (c == s[index]) {
                    ++index;
                } else {
                    return false;
                }
            }
            if (index == s.size()) {
                return true;
            }
        }

        return index == s.size();
    }
};