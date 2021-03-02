#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;

        dfs(nums, res, path, 0);

        return res;
    }

private:
    void dfs(std::vector<int>& nums, std::vector<std::vector<int>>& res, std::vector<int>& path, int index)
    {
        if (path.size() >= 2) res.push_back(path);

        std::unordered_set<int> used;

        for (int i = index; i < nums.size(); ++i)
        {
            if (!path.empty() && nums[i] < path.back() || used.find(nums[i]) != used.end()) continue;

            used.insert(nums[i]);
            path.push_back(nums[i]);
            dfs(nums, res, path, i + 1);
            path.pop_back();
        }
    }
};