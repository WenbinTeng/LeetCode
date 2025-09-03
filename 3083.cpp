#include <algorithm>
#include <string>
#include <unordered_set>

class Solution {
  public:
    bool isSubstringPresent(std::string s) {
        std::string r = s;
        std::unordered_set<std::string> dict;

        std::reverse(r.begin(), r.end());

        for (int i = 0; i < r.size() - 1; i++) {
            dict.insert(r.substr(i, 2));
        }

        for (int i = 0; i < s.size() - 1; i++) {
            if (dict.count(s.substr(i, 2))) {
                return true;
            }
        }

        return false;
    }
};