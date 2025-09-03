#include <cmath>
#include <vector>

class Solution {
  public:
    int nonSpecialCount(int l, int r) {
        int n = std::sqrt(r);
        int res = r - l + 1;
        std::vector<int> a(n + 1);

        for (int i = 2; i <= n; i++) {
            if (a[i] == 0) {
                for (int j = i * 2; j <= n; j += i) {
                    a[j] = 1;
                }
                if (i * i >= l && i * i <= r) {
                    res--;
                }
            }
        }

        return res;
    }
};