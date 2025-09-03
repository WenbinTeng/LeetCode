#include <vector>

class Solution {
  public:
    int totalHammingDistance(std::vector<int> &nums) {
        int res = 0;
        int cnt = 0;

        for (int i = 0; i < 32; ++i) {
            cnt = 0;

            for (const auto &num : nums) {
                cnt += (num >> i) & 1;
            }

            res += cnt * (nums.size() - cnt);
        }

        return res;
    }
};