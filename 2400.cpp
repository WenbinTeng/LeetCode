#include <algorithm>
#include <vector>

class Solution {
  public:
    int numberOfWays(int startPos, int endPos, int k) {
        if ((k - std::abs(startPos - endPos)) % 2 != 0 ||
            k < std::abs(startPos - endPos))
            return 0;
        else if (k == std::abs(startPos - endPos))
            return 1;
        else
            return combination(std::abs(startPos - endPos), k);
    }

  private:
    int mod = 1e+9 + 7;

    int combination(int m, int n) {
        std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1));

        for (int i = 0; i <= n; ++i) {
            f[i][0] = 1;

            for (int j = 1; j <= i; ++j) {
                f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % mod;
            }
        }

        return f[n][(m + n) / 2];
    }
};