#include <vector>

class Solution {
public:
    std::vector<int> getAverages(std::vector<int>& nums, int k) {
        int n = nums.size();
        int l = 2 * k + 1;
        long long acc = 0;
        std::vector<int> res(nums.size(), -1);

        if (n > k * 2)
        {
            for (int i = 0; i <= k * 2; ++i)
            {
                acc += nums[i];
            }

            res[k] = acc / l;

            for (int i = k + 1; i + k < n; ++i)
            {
                acc -= nums[i - k - 1];
                acc += nums[i + k];
                res[i] = acc / l;
            }
        }

        return res;
    }
};