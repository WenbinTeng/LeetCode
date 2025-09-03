#include <algorithm>
#include <vector>

class Solution {
  public:
    int maxLength(std::vector<int> &nums) {
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            long long prod = nums[i];
            long long gcd = nums[i];
            long long lcm = nums[i];
            for (int j = i + 1; j < n; j++) {
                prod = prod * nums[j];
                gcd = std::__gcd(gcd, (long long)nums[j]);
                lcm = lcm * nums[j] / std::__gcd(lcm, (long long)nums[j]);
                if (prod == gcd * lcm)
                    res = std::max(res, j - i + 1);
                else
                    break;
            }
        }

        return res;
    }
};