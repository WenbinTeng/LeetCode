#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        const int n = nums.size();
        std::vector<std::vector<int>> res;
        std::vector<int> used(n, 0);
        std::vector<int> path;

        auto backtrack = [&](auto &self) -> void {
            if (path.size() == n) {
                res.push_back(path);
                return;
            }
            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    used[i] = 1;
                    path.push_back(nums[i]);
                    self(self);
                    path.pop_back();
                    used[i] = 0;
                }
            }
        };

        backtrack(backtrack);

        return res;
    }
};