#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> targetIndices(std::vector<int> &nums, int target) {
        std::vector<int> res;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                res.push_back(i);
            }
        }

        return res;
    }
};