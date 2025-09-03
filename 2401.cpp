#include <vector>

class Solution {
  public:
    int longestNiceSubarray(std::vector<int> &nums) {
        int res = 0;
        std::vector<int> cnt(31, 0);

        for (int i = 0, j = 0; i < nums.size(); i++) {
            for (int k = 0; k < 30; k++) {
                cnt[k] += nums[i] >> k & 1;
            }

            while (j <= i && !check(cnt)) {
                for (int k = 0; k < 30; k++) {
                    cnt[k] -= nums[j] >> k & 1;
                }

                j++;
            }

            res = std::max(res, i - j + 1);
        }

        return res;
    }

  private:
    bool check(std::vector<int> &cnt) {
        for (int i = 0; i < 30; i++) {
            if (cnt[i] > 1) {
                return false;
            }
        }

        return true;
    }
};