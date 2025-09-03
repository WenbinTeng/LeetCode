#include <vector>

class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        const int n = nums1.size();
        const int m = nums2.size();
        int res = 0;

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    res = std::max(res, dp[i + 1][j + 1]);
                }
            }
        }

        return res;
    }
};