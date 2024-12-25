#include <vector>
#include <unordered_map>

class Solution {
public:
    int countPairs(std::vector<std::vector<int>>& coordinates, int k) {
        long long res = 0;
        std::unordered_map<long long, int> cnt;

        for (int i = 0; i < coordinates.size(); i++) {
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            long long key = ((long long)y << 32) + x;
            for (int i = 0; i <= k; i++) {
                int px = x ^ i;
                int py = y ^ (k - i);
                long long pkey = ((long long)py << 32) + px;
                if (cnt.count(pkey)) {
                    res += cnt[pkey];
                }
            }
            cnt[key]++;
        }

        return res;
    }
};