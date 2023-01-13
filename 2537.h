#include <unordered_map>
#include <vector>

class Solution {
public:
    long long countGood(std::vector<int> &nums, int K) {
        long long res = 0;
        long long now = 0;
        std::unordered_map<int, int> cnt;

        for (int i = 0, j = 0; i < nums.size(); i++) {
            long long x = ++cnt[nums[i]];

            now -= (x - 1) * (x - 2) / 2;
            now += x * (x - 1) / 2;
            while (j <= i && now >= K) {
                long long x = --cnt[nums[j]];
                now -= (x + 1) * x / 2;
                now += x * (x - 1) / 2;
                j++;
            }

            res += j;
        }

        return res;
    }
};