#include <string>
#include <unordered_map>

class Solution {
  public:
    bool digitCount(std::string num) {
        std::unordered_map<char, int> cnt;

        for (const auto c : num) {
            cnt[c]++;
        }

        for (int i = 0; i < num.size(); ++i) {
            if (cnt[(char)i + '0'] != num[i] - '0') {
                return false;
            }
        }

        return true;
    }
};