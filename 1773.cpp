#include <string>
#include <vector>

class Solution {
  public:
    int countMatches(std::vector<std::vector<std::string>> &items,
                     std::string ruleKey, std::string ruleValue) {
        int res = 0;
        int idx = -1;

        if (ruleKey == "type")
            idx = 0;
        if (ruleKey == "color")
            idx = 1;
        if (ruleKey == "name")
            idx = 2;

        if (idx == -1)
            return 0;

        for (const auto &item : items)
            if (item[idx] == ruleValue)
                ++res;

        return res;
    }
};