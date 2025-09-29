#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                                 int target) {
        const int n = candidates.size();
        std::vector<std::vector<int>> res;
        std::vector<int> used(n, 0);
        std::vector<int> path;

        auto backtrack = [&](auto &self, int index, int sum) -> void {
            if (sum == target) {
                res.push_back(path);
                return;
            }
            if (index == n) {
                return;
            }

            self(self, index + 1, sum);

            if (sum + candidates[index] <= target) {
                path.push_back(candidates[index]);
                self(self, index, sum + candidates[index]);
                path.pop_back();
            }
        };

        backtrack(backtrack, 0, 0);

        return res;
    }
};