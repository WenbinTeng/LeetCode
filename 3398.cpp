#include <string>

class Solution {
  public:
    int minLength(std::string s, int numOps) {
        int n = s.length();

        auto check = [&](int m) -> bool {
            int cnt = 0;
            if (m == 1) {
                for (int i = 0; i < n; i++) {
                    cnt += (s[i] ^ i) & 1;
                }
                cnt = std::min(cnt, n - cnt);
            } else {
                int k = 0;
                for (int i = 0; i < n; i++) {
                    k++;
                    if (i == n - 1 || s[i] != s[i + 1]) {
                        cnt += k / (m + 1);
                        k = 0;
                    }
                }
            }
            return cnt <= numOps;
        };

        int left = 0;
        int right = n;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid))
                right = mid;
            else
                left = mid;
        }

        return right;
    }
};