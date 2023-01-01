#include <vector>

class Solution {
public:
    int countMaxOrSubsets(std::vector<int> &nums) {
        for (const auto &num : nums) {
            maxValue = maxValue | num;
        }

        dfs(nums, 0, 0);

        return cntValue;
    }

private:
    int maxValue = 0;
    int cntValue = 0;

    void dfs(std::vector<int> &nums, int value, int index) {
        if (index == nums.size()) {
            if (value == maxValue) {
                ++cntValue;
            }

            return;
        }

        dfs(nums, value | nums[index], index + 1);
        dfs(nums, value, index + 1);
    }
};