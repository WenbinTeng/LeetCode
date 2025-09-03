#include <string>
#include <vector>

class Solution {
  public:
    int strStr(std::string haystack, std::string needle) {
        return KMPMatch(haystack, needle);
    }

  private:
    int KMPMatch(std::string s, std::string p) {
        if (p.empty())
            return 0;

        std::vector<int> next(p.size() + 1);
        next[0] = 0;
        int i;
        int j;

        for (i = 1, j = 0; i < p.size();) {
            if (j == 0 || p[i - 1] == p[j - 1]) {
                i++;
                j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }

        for (i = 1, j = 1; i <= s.size() && j <= p.size();) {
            if (j == 0 || s[i - 1] == p[j - 1]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        return j > p.size() ? i - p.size() - 1 : -1;
    }
};