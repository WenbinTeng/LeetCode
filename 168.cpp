#include <string>

class Solution {
  public:
    std::string convertToTitle(int columnNumber) {
        std::string res;

        while (columnNumber > 0) {
            --columnNumber;
            res += columnNumber % 26 + 'A';
            columnNumber /= 26;
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
};