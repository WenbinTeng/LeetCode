#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findLonely(std::vector<int>& nums) {
        std::vector<int> res;
        std::unordered_map<int, int> um;

        for (const auto num : nums)
        {
            ++um[num];
        }

        for (const auto [num, count] : um)
        {
            if (count == 1 && !um.count(num - 1) && !um.count(num + 1))
            {
                res.push_back(num);
            }
        }

        return res;
    }
};