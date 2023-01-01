#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    int minElements(std::vector<int> &nums, int limit, int goal) {
        long long sum = 0;
        for (const auto &num : nums)
            sum += num;
        return sum == goal ? 0 : (std::abs(sum - goal) - 1) / limit + 1;
    }
};