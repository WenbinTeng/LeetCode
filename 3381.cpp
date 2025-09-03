#include <vector>

class Solution {
  public:
    long long maxSubarraySum(std::vector<int> &nums, int k) {
        long long res = LLONG_MIN;
        long long s = 0;
        std::vector<long long> min_s(k, LLONG_MAX / 2);
        min_s.back() = 0;

        for (int j = 0; j < nums.size(); j++) {
            s += nums[j];
            int i = j % k;
            res = std::max(res, s - min_s[i]);
            min_s[i] = std::min(min_s[i], s);
        }

        return res;
    }
};