#include <unordered_map>
#include <vector>

class Solution {
  public:
    int countNicePairs(std::vector<int> &nums) {
        int res = 0;
        int mod = 1e+9 + 7;
        std::unordered_map<int, int> um;

        for (const auto num : nums) {
            int t = num;
            int r = 0;

            while (t) {
                r = r * 10 + t % 10;
                t /= 10;
            }

            res = (res + um[num - r]) % mod;
            um[num - r]++;
        }

        return res;
    }
};