#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::string res;

        auto cmp = [](int a, int b) { return std::to_string(a) + std::to_string(b) > std::to_string(b) + std::to_string(a); };

        std::sort(nums.begin(), nums.end(), cmp);

        for (const auto& num : nums) res += std::to_string(num);

        if (res.front() == '0') return "0";

        return res;
    }
};