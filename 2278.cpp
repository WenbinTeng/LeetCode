#include <string>

class Solution {
  public:
    int percentageLetter(std::string s, char letter) {
        int cnt = 0;

        for (const auto c : s) {
            if (c == letter) {
                ++cnt;
            }
        }

        return cnt * 100 / s.size();
    }
};