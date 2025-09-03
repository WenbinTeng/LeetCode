#include <string>
#include <vector>

class Solution {
  public:
    bool isSubsequence(std::string s, std::string t) {
        int m = s.size();
        int n = t.size();
        int i = 0;
        int j = 0;

        while (i < m && j < n) {
            if (s[i] == t[j])
                ++i;
            ++j;
        }

        return i == m;
    }
};