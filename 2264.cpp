#include <string>

class Solution {
  public:
    std::string largestGoodInteger(std::string num) {
        std::string res;
        int digit = -1;

        for (int i = 1; i < num.size() - 1; ++i) {
            if (num[i] == num[i - 1] && num[i] == num[i + 1]) {
                digit = std::max(digit, (int)num[i]);
            }
        }

        if (digit == -1) {
            return "";
        } else {
            res.push_back(digit);
            res.push_back(digit);
            res.push_back(digit);
        }

        return res;
    }
};