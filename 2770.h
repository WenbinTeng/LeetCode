#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumJumps(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::vector<int> cnt(n, -1);

        cnt[0] = 0;
        for (int r = 1; r < n; r++) {
            for (int l = r - 1; l >= 0; l--) {
                if (std::abs(nums[r] - nums[l]) <= target && cnt[l] != -1) {
                    cnt[r] = std::max(cnt[r], cnt[l] + 1);
                }
            }
        }

        return cnt[n - 1];
    }
};