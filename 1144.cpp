#include <vector>

class Solution {
  public:
    int movesToMakeZigzag(std::vector<int> &nums) {
        int n = nums.size();
        int cnt1 = 0;
        int cnt2 = 0;

        for (int i = 0; i < n; i++) {
            int l = i - 1 >= 0 ? nums[i - 1] : nums[i] + 1;
            int r = i + 1 < n ? nums[i + 1] : nums[i] + 1;
            int min = std::min(l, r);

            if (i % 2 == 0) {
                if (nums[i] >= min)
                    cnt1 += nums[i] - min + 1;
            } else {
                if (nums[i] >= min)
                    cnt2 += nums[i] - min + 1;
            }
        }

        return std::min(cnt1, cnt2);
    }
};