#include <vector>

class Solution {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int res = INT_MAX;
        std::vector<int> prevSum(nums.size() + 1);

        prevSum[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            prevSum[i + 1] = prevSum[i] + nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int len = j - i + 1;
                if (len < l)
                    continue;
                if (len > r)
                    break;
                int sum = prevSum[j + 1] - prevSum[i];
                if (sum > 0)
                    res = std::min(res, sum);
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};