#include <vector>

class Solution {
public:
    int subsetXORSum(std::vector<int> &nums) {
        dfs(nums, 0, 0);
        return res;
    }

private:
    int res = 0;

    void dfs(std::vector<int> &nums, int x, int index) {
        if (index == nums.size()) {
            res += x;
            return;
        }

        dfs(nums, x, index + 1);
        x = x ^ nums[index];
        dfs(nums, x, index + 1);
        x = x ^ nums[index];
    }
};