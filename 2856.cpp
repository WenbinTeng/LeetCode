#include <algorithm>
#include <vector>

class Solution {
  public:
    int minLengthAfterRemovals(std::vector<int> &nums) {
        int n = nums.size();
        int x = nums[n / 2];
        int maxCnt = std::upper_bound(nums.begin(), nums.end(), x) -
                     std::lower_bound(nums.begin(), nums.end(), x);
        return std::max(maxCnt * 2 - n, n % 2);
    }
};