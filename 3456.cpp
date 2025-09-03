#include <string>

class Solution {
  public:
    bool hasSpecialSubstring(std::string s, int k) {
        int n = s.size();

        for (int i = 0; i <= n - k; i++) {
            bool hasStr = true;
            if (i - 1 >= 0 && s[i] == s[i - 1])
                continue;
            if (i + k < n && s[i + k - 1] == s[i + k])
                continue;
            for (int j = 1; j < k; j++) {
                if (s[i + j - 1] != s[i + j]) {
                    hasStr = false;
                    break;
                }
            }
            if (hasStr)
                return true;
        }

        return false;
    }
};