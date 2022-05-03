#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> intersection(std::vector<std::vector<int>>& nums) {
        std::vector<int> res;
        std::unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < nums[i].size(); ++j)
            {
                ++um[nums[i][j]];
            }
        }

        for (const auto [val, cnt] : um)
        {
            if (cnt == nums.size())
            {
                res.push_back(val);
            }
        }

        std::sort(res.begin(), res.end());

        return res;
    }
};