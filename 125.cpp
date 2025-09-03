#include <string>

class Solution {
  public:
    bool isPalindrome(std::string s) {
        if (s.empty())
            return true;

        for (auto iter = s.begin(); iter != s.end();) {
            if (*iter >= '0' && *iter <= '9') {
                iter++;
                continue;
            }
            if (*iter >= 'a' && *iter <= 'z') {
                iter++;
                continue;
            }
            if (*iter >= 'A' && *iter <= 'Z') {
                *(iter++) += 'a' - 'A';
                continue;
            }

            iter = s.erase(iter);
        }

        return checkShrink(s, 0, s.size() - 1);
    }

  private:
    bool checkShrink(std::string &s, int i, int j) {
        while (i <= j) {
            if (s[i++] != s[j--])
                return false;
        }

        return true;
    }
};