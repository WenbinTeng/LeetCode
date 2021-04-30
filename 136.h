#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int res = 0;

        for (const auto& num : nums)
        {
            res ^= num;
        }

        return res;
    }
};