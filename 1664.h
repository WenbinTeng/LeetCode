#include <vector>

class Solution {
public:
    int waysToMakeFair(std::vector<int> &nums) {
        int res = 0;
        int s = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
            s += i % 2 ? nums[i] : -nums[i];

        for (int i = 0; i < n; ++i) {
            s -= i % 2 ? nums[i] : -nums[i];
            res += s == 0;
            s -= i % 2 ? nums[i] : -nums[i];
        }

        return res;
    }
};