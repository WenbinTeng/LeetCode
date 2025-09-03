#include <string>

class Solution {
  public:
    int countHomogenous(std::string s) {
        long long res = 0;

        for (long long i = 0, j = 0; i < s.size(); i = j) {
            while (j < s.size() && s[i] == s[j])
                ++j;
            res += (j - i + 1) * (j - i) / 2;
        }

        return res % (long long)(1e+9 + 7);
    }
};