#include <string>

class Solution {
public:
    int numSub(std::string s) {
        const int mod = 1e+9+7;
        int n = s.size();
        int res = 0;
        int l = 0;
        int r = 0;

        while (l < n) {
            if (s[l] == '1') {
                r = l + 1;
                while (r < n) {
                    if (s[r] == '0')
                        break;
                    r++;
                }
                int len = r - l;
                long long cnt = (long long)(len + 1) * len / 2;
                res = (res + cnt) % mod;
                l = r;
            }
            l++;
            r = l;
        }

        return res;
    }
};