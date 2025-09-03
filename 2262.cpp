#include <string>
#include <vector>

class Solution {
  public:
    long long appealSum(std::string s) {
        long long res = 0;
        std::vector<int> f(26);

        for (int i = 0; i < 26; ++i) {
            f[i] = s.size();
        }

        for (int i = s.size() - 1; i >= 0; --i) {
            f[s[i] - 'a'] = i;

            for (int j = 0; j < 26; ++j) {
                if (f[j] < s.size()) {
                    res += s.size() - f[j];
                }
            }
        }

        return res;
    }
};