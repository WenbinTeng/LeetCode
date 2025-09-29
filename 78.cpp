#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        const int n = nums.size();
        std::vector<std::vector<int>> res;
        std::vector<int> path;

        auto backtrack = [&](auto &self, int index) -> void {
            if (index == n) {
                res.push_back(path);
                return;
            }
            self(self, index + 1);
            path.push_back(nums[index]);
            self(self, index + 1);
            path.pop_back();
        };

        backtrack(backtrack, 0);

        return res;
    }
};