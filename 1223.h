#include <vector>

class Solution {
public:
    int dieSimulator(int n, std::vector<int>& rollMax) {
        int res = 0;
        int mod = 1e+9+7;
        std::vector d(n + 1, std::vector(6, std::vector<int>(16)));

        for (int j = 0; j < 6; j++) {
            d[1][j][1] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = 1; k <= rollMax[j]; k++) {
                    for (int p = 0; p < 6; p++) {
                        if (p != j) {
                            d[i][p][1] = (d[i][p][1] + d[i - 1][j][k]) % mod;
                        } else if (k + 1 <= rollMax[j]) {
                            d[i][p][k + 1] = (d[i][p][k + 1] + d[i - 1][j][k]) % mod;
                        }
                    }
                }
            }
        }
        
        for (int j = 0; j < 6; j++) {
            for (int k = 1; k <= rollMax[j]; k++) {
                res = (res + d[n][j][k]) % mod;
            }
        }

        return res;
    }
};