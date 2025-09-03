#include <vector>

class Solution {
  public:
    int idealArrays(int n, int maxValue) {
        long long res = 0;
        int max = 0;

        f.resize(maxValue + 1);
        for (int i = 2; i <= maxValue; i++) {
            if (f[i].empty()) {
                for (int j = i; j <= maxValue; j += i) {
                    int x = j, y = 0;
                    for (; x % i == 0; x /= i)
                        y++;
                    f[j].push_back(y);
                    max = std::max(max, y);
                }
            }
        }

        inv.resize(max + 5);
        inv[1] = 1;
        for (int i = 2; i <= max; i++) {
            inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        }

        for (int i = 1; i <= maxValue; i++) {
            long long t = 1;
            for (int x : f[i])
                t = (t * C(n + x - 1, x)) % mod;
            res = (res + t) % mod;
        }

        return res;
    }

  private:
    const int mod = 1e+9 + 7;
    std::vector<long long> inv;
    std::vector<std::vector<int>> f;

    long long C(int a, int b) {
        if (b > a)
            return 0;

        long long ret = 1;

        for (int i = 1; i <= b; i++) {
            ret = (ret * (a - i + 1) % mod * inv[i]) % mod;
        }

        return ret;
    }
};