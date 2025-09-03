#include <unordered_map>
#include <vector>

class Solution {
  public:
    int maxSubarrayLength(std::vector<int> &nums, int k) {
        int res = 0;
        int l = 0;
        int r = 0;
        std::unordered_map<int, int> dict;

        while (r < nums.size()) {
            if (++dict[nums[r]] > k) {
                res = std::max(res, r - l);
                while (l < r && dict[nums[r]] > k) {
                    dict[nums[l]]--;
                    l++;
                }
            }
            r++;
        }

        return std::max(res, r - l);
    }
};