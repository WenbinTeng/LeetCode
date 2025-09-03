#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                                 int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> sel;

        dfs(candidates, res, sel, target, 0);

        return res;
    }

  private:
    void dfs(std::vector<int> &candidates, std::vector<std::vector<int>> &res,
             std::vector<int> &sel, int target, int index) {
        if (index == candidates.size())
            return;

        if (target == 0) {
            res.push_back(sel);
            return;
        }

        dfs(candidates, res, sel, target, index + 1);

        if (target - candidates[index] >= 0) {
            sel.push_back(candidates[index]);
            dfs(candidates, res, sel, target - candidates[index], index);
            sel.pop_back();
        }
    }
};