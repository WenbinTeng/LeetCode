#include <vector>
#include <algorithm>

class Solution {
public:
    int findGCD(std::vector<int>& nums) {
        return std::__gcd(*std::max_element(nums.begin(), nums.end()), *std::min_element(nums.begin(), nums.end()));
    }
};