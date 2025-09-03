#include <vector>

class Solution {
  public:
    int beautifulSplits(std::vector<int> &nums) {
        int res = 0;
        int n = nums.size();
        std::vector lcp(n + 1, std::vector<int>(n + 1));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= i; j--) {
                if (nums[i] == nums[j]) {
                    lcp[i][j] = lcp[i + 1][j + 1] + 1;
                }
            }
        }

        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i <= j - i && lcp[0][i] >= i || lcp[i][j] >= j - i) {
                    res++;
                }
            }
        }
        return res;
    }
};