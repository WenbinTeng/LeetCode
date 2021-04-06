#include <vector>
#include <algorithm>

class Solution {
public:
    int countDifferentSubsequenceGCDs(std::vector<int>& nums) {
        int res = 0;
        int gcd = 0;
        int n = 200000;
        std::vector<bool> vis(n + 1);

        for (int x: nums) vis[x] = true;
        
        for (int i = 1; i <= n; ++i)
        {
            gcd = -1;

            for (int j = i; j <= n; j += i)
            {
                if (vis[j]) gcd = gcd == - 1 ? j : std::__gcd(gcd, j);
            }

            if (gcd == i) ++res;
        }

        return res;
    }
};