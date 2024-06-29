#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        std::vector<bool> used(nums.size(), false);
        std::sort(nums.begin(), nums.end());
        dfs(nums, res, path, used, 0);
        return res;
    }

private:
    void dfs(std::vector<int> &nums, std::vector<std::vector<int>> &res, std::vector<int> &path, std::vector<bool> &used, int index) {
        res.push_back(path);

        for (int i = index; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, res, path, used, i + 1);
            path.pop_back();
            used[i] = false;
        }
    }
};