#include <vector>

class Solution {
  public:
    int rearrangeSticks(int n, int k) {
        std::vector<int> f(k + 1);
        std::vector<int> g(k + 1);

        f[0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                g[j] = ((long long)f[j] * (i - 1) + f[j - 1]) % (int)(1e+9 + 7);
            }
            f = std::move(g);
            g = std::vector<int>(k + 1);
        }

        return f[k];
    }
};