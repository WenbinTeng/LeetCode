#include <vector>

const int MOD = 1e+9 + 7;
const int MAX = 1e+5;

long long F[MAX];     // F[i] = i!
long long INV_F[MAX]; // INV_F[i] = i!^-1

long long qpow(long long x, int n) {
    long long res = 1;
    for (; n; n /= 2) {
        if (n % 2) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
    }
    return res;
}

auto init = []() {
    F[0] = 1;
    for (int i = 1; i < MAX; i++) {
        F[i] = F[i - 1] * i % MOD;
    }

    INV_F[MAX - 1] = qpow(F[MAX - 1], MOD - 2);
    for (int i = MAX - 1; i; i--) {
        INV_F[i - 1] = INV_F[i] * i % MOD;
    }
    return 0;
};

long long comb(int n, int m) {
    return F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD;
}

class Solution {
  public:
    int countGoodArrays(int n, int m, int k) {
        return comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;
    }
};