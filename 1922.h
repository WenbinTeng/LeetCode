#include <vector>

class Solution {
public:
    int countGoodNumbers(long long n) {
        return (quickPow(5, (n / 2) + (n % 2)) * quickPow(4, n / 2)) % mod;
    }

private:
    const int mod = 1e+9+7;

    long long quickPow(long long a, long long b) {
        long long res = 1;
        long long base = a;
        
        while (b) {
            if (b & 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            b /= 2;
        }

        return res % mod;
    }
};