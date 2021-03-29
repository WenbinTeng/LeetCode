#include <vector>

class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors <= 3) return primeFactors;

        if (primeFactors % 3 == 0) return (long long)myPow(3, primeFactors / 3) % (int)(1e+9+7);
        else if (primeFactors % 3 == 1) return 4 * (long long)myPow(3, (primeFactors - 4) / 3) % (int)(1e+9+7);
        else if (primeFactors % 3 == 2) return 2 * (long long)myPow(3, (primeFactors - 0) / 3) % (int)(1e+9+7);

        return 0;
    }

private:
    long long myPow(long long x, long long n)
    {
        long long res = 1;
        
        while (n)
        {
            if (n & 1) res = (res * x) % (int)(1e+9+7);
            x = (x * x) % (int)(1e+9+7);
            n = n >> 1;
        }

        return res;
    }
};