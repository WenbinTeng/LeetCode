#include <vector>

class Solution {
public:
    int maxNonDecreasingLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        int res = 0;
        std::vector<int> dp1(n, 1);
        std::vector<int> dp2(n, 1);

        for (int i = 1; i < n; i++) {
            if (nums1[i] >= nums1[i - 1])
                dp1[i] = std::max(dp1[i], dp1[i - 1] + 1);
            if (nums1[i] >= nums2[i - 1])
                dp1[i] = std::max(dp1[i], dp2[i - 1] + 1);
            if (nums2[i] >= nums1[i - 1])
                dp2[i] = std::max(dp2[i], dp1[i - 1] + 1);
            if (nums2[i] >= nums2[i - 1])
                dp2[i] = std::max(dp2[i], dp2[i - 1] + 1);
        }

        for (int i = 0; i < n; i++) {
            res = std::max(res, dp1[i]);
            res = std::max(res, dp2[i]);
        }

        return res;
    }
};