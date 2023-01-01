#include <algorithm>
#include <vector>

class Solution {
public:
    long long minimalKSum(std::vector<int> &nums, int k) {
        long long res = 0;

        nums.push_back(0);
        nums.push_back((int)2e+9);
        std::sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); ++i) {
            int fill = nums[i] - nums[i - 1] - 1;

            if (fill < 0) {
                continue;
            } else if (fill >= k) {
                res += (long long)(nums[i - 1] + 1 + nums[i - 1] + k) * k / 2;
                break;
            } else {
                res += (long long)(nums[i - 1] + nums[i]) * fill / 2;
                k -= fill;
            }
        }

        return res;
    }
};