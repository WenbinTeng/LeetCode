#include <unordered_map>
#include <vector>

class Solution {
  public:
    int countSubarrays(std::vector<int> &nums, int k) {
        int res = 0;
        int pos = std::find(nums.begin(), nums.end(), k) - nums.begin();
        std::unordered_map<int, int> cnt;

        cnt[0] = 1;
        for (int i = pos - 1, x = 0; i >= 0; --i) {
            x += nums[i] < k ? 1 : -1;
            ++cnt[x];
        }

        res = cnt[0] + cnt[-1];
        for (int i = pos + 1, x = 0; i < nums.size(); ++i) {
            x += nums[i] > k ? 1 : -1;
            res += cnt[x] + cnt[x - 1];
        }

        return res;
    }
};