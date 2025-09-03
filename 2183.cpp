#include <unordered_map>
#include <vector>

class Solution {
  public:
    long long coutPairs(vector<int> &nums, int k) {
        long long res = 0;
        std::unordered_map<int, int> um;

        for (int num : nums) {
            ++um[__gcd(num, k)];
        }

        for (auto [k1, v1] : um) {
            for (auto [k2, v2] : um) {
                if (1LL * k1 * k2 % k == 0) {
                    if (k1 < k2) {
                        res += 1LL * v1 * v2;
                    } else if (k1 == k2) {
                        res += 1LL * v1 * (v1 - 1) / 2;
                    }
                }
            }
        }

        return res;
    }
};