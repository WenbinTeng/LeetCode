#include <vector>

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod = 1e+9 + 7;
        std::vector<long long> f(n + 1);
        std::vector<long long> g(n + 1);
        f[1] = g[1] = 1;

        for (int i = 2; i <= n; i++) {
            int L = std::max(0, i - forget);
            int R = std::max(0, i - delay);
            f[i] = (g[R] - g[L] + mod) % mod;
            g[i] = (g[i - 1] + f[i]) % mod;
        }

        return (g[n] - g[std::max(0, n - forget)] + mod) % mod;
    }
};