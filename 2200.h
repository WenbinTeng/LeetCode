#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::vector<int> findKDistantIndices(std::vector<int>& nums, int key, int k) {
        std::vector<int> res;
        std::unordered_set<int> us;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == key)
            {
                for (int j = 0; j < nums.size(); ++j)
                {
                    if (std::abs(i - j) <= k)
                    {
                        us.insert(j);
                    }
                }
            }
        }

        for (const auto e : us)
        {
            res.push_back(e);
        }

        std::sort(res.begin(), res.end());

        return res;
    }
};