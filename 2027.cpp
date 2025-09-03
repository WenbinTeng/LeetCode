#include <string>

class Solution {
  public:
    int minimumMoves(std::string s) {
        int res = 0;
        int pos = 0;

        while (pos < s.size()) {
            if (s[pos] == 'X') {
                ++res;
                pos += 3;
            } else
                ++pos;
        }

        return res;
    }
};