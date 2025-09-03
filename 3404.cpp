#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    long long numberOfSubsequences(std::vector<int> &nums) {
        int n = nums.size();
        long long ans = 0;
        std::unordered_map<double, int> cnt;

        for (int i = 4; i < n - 2; i++) {
            double b = nums[i - 2];
            for (int j = 0; j < i - 3; j++) {
                cnt[nums[j] / b]++;
            }
            double c = nums[i];
            for (int j = i + 2; j < n; j++) {
                ans += cnt[nums[j] / c];
            }
        }

        return ans;
    }
};