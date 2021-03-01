#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> rec;

        dfs(nums, res, rec, 0);

        return res;
    }

private:
    void dfs(std::vector<int>& nums, std::vector<std::vector<int>>& res, std::vector<int>& rec, int index)
    {
        if (index == nums.size()) {res.push_back(rec); return;}

        rec.push_back(nums[index]);
        dfs(nums, res, rec, index + 1);
        rec.pop_back();
        dfs(nums, res, rec, index + 1);
    }
};