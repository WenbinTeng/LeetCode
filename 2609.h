#include <string>

class Solution {
public:
    int findTheLongestBalancedSubstring(std::string s) {
        int res = 0;
        int len = s.size();

        auto isBalanced = [](std::string str) -> bool {
            int length = str.size();
            if (length % 2 == 1)
                return false;
            for (int i = 0; i < length / 2; i++) {
                if (str[i] != '0' || str[length - 1 - i] != '1') {
                    return false;
                }
            }
            return true;
        };

        for (int i = 0; i < len; i++) {
            for (int j = len - 1; j > i; j--) {
                if (isBalanced(s.substr(i, j - i + 1))) {
                    res = std::max(res, j - i + 1);
                    break;
                }
            }
        }

        return res;
    }
};