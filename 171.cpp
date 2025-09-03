#include <string>

class Solution {
  public:
    int titleToNumber(std::string columnTitle) {
        int res = 0;
        long long times = 1;

        while (!columnTitle.empty()) {
            res += (int)(columnTitle.back() - 'A' + 1) * times;
            times *= 26;
            columnTitle.pop_back();
        }

        return res;
    }
};