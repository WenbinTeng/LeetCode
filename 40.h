#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> sel;

        std::sort(candidates.begin(), candidates.end());

        dfs(candidates, res, sel, target, 0);

        return res;
    }

private:
    void dfs(std::vector<int>& candidates, std::vector<std::vector<int>>& res, std::vector<int>& sel, int target, int index)
    {
        if (target == 0) {res.push_back(sel); return;}

        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i - 1] == candidates[i]) continue;

            if (target - candidates[i] >= 0)
            {
                sel.push_back(candidates[i]);
                dfs(candidates, res, sel, target - candidates[i], i + 1);
                sel.pop_back();
            }
        }
    }
};