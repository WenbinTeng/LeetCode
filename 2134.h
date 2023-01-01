#include <vector>

class Solution {
public:
    int minSwaps(std::vector<int> &nums) {
        int sum = 0;
        int cnt = 0;
        int max = 0;

        for (const auto num : nums) {
            sum += num;
        }

        for (int i = 0; i < sum; ++i) {
            cnt += nums[i];
        }

        for (int i = sum; i < nums.size() + sum; ++i) {
            cnt += nums[i % nums.size()];
            cnt -= nums[i - sum];
            max = std::max(max, cnt);
        }

        return sum - max;
    }
};