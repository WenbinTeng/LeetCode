#include <numeric>
#include <vector>

class Solution {
  public:
    int minOperations(std::vector<int> &nums, int x) {
        int n = nums.size();
        int res = n + 1;
        int lsum = 0;
        int rsum = std::accumulate(nums.begin(), nums.end(), 0);

        if (rsum < x)
            return -1;

        for (int left = -1, right = 0; left < n; ++left) {
            if (left != -1) {
                lsum += nums[left];
            }

            while (right < n && lsum + rsum > x) {
                rsum -= nums[right];
                ++right;
            }

            if (lsum + rsum == x) {
                res = std::min(res, left + 1 + n - right);
            }
        }

        return res > n ? -1 : res;
    }
};