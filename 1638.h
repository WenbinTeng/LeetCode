#include <string>

class Solution {
public:
    int countSubstrings(std::string s, std::string t) {
        int res = 0;
        int m = s.size();
        int n = t.size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int diff = 0;
                for (int k = 0; i + k < m && j + k < n; k++) {
                    diff += s[i + k] == t[j + k] ? 0 : 1;
                    if (diff > 1) {
                        break;
                    } else if (diff == 1) {
                        res++;
                    }
                }
            }
        }

        return res;
    }
};