#include <vector>

class Solution {
  public:
    int maxUncrossedLines(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::vector<std::vector<int>> dp(nums1.size() + 1,
                                         std::vector<int>(nums2.size() + 1));

        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[nums1.size()][nums2.size()];
    }
};