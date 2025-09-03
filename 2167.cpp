#include <string>
#include <vector>

class Solution {
  public:
    int minimumTime(std::string s) {
        int res = INT_MAX;
        std::vector<int> ldp(s.size() + 1);
        std::vector<int> rdp(s.size() + 1);

        for (int i = 1; i <= s.size(); ++i) {
            if (s[i - 1] == '1') {
                ldp[i] = std::min(ldp[i - 1] + 2, i);
            } else {
                ldp[i] = ldp[i - 1];
            }
        }

        for (int i = s.size(); i >= 1; --i) {
            if (s[i - 1] == '1') {
                rdp[i - 1] = std::min(rdp[i] + 2, (int)s.size() - i + 1);
            } else {
                rdp[i - 1] = rdp[i];
            }
        }

        for (int i = 0; i <= s.size(); ++i) {
            res = std::min(res, ldp[i] + rdp[i]);
        }

        return res;
    }
};