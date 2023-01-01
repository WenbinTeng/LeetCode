#include <unordered_map>
#include <vector>

class Solution {
public:
    int firstMissingPositive(std::vector<int> &nums) {
        std::unordered_map<int, bool> um;

        for (const auto &iter : nums)
            if (iter > 0)
                um[iter] = true;

        for (int i = 1; i < INT_MAX; i++)
            if (um.find(i) == um.end())
                return i;

        return INT_MAX;
    }
};