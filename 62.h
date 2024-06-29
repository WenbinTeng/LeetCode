#include <cstdlib>

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res = 1;

        for (int i = n, j = 1; j < m; i++, j++) {
            res = res * i / j;
        }

        return res;
    }
};