#include <vector>

class Solution {
  public:
    long long countAlternatingSubarrays(std::vector<int> &nums) {
        long long res = 0;
        int l = 0;
        int r = 1;

        while (r < nums.size()) {
            if (nums[r] == nums[r - 1]) {
                long long len = r - l;
                long long sum = len * (len + 1) / 2;
                res += sum;
                l = r;
            }
            r++;
        }

        return res + ((long long)(r - l) * (r - l + 1) / 2);
    }
};