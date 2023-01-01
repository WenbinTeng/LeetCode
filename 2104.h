#include <numeric>
#include <vector>

class Solution {
public:
    long long subArrayRanges(std::vector<int> &nums) {
        long long res = 0;

        for (int i = 0; i < nums.size(); ++i) {
            dfs(nums, i + 1, nums[i], nums[i]);
        }

        for (int i = 0; i < sums.size(); ++i) {
            res += sums[i];
        }

        return res;
    }

private:
    std::vector<long long> sums;

    void dfs(std::vector<int> &nums, int index, int minValue, int maxValue) {
        sums.push_back((long long)maxValue - (long long)minValue);

        if (index == nums.size())
            return;

        if (minValue > nums[index])
            minValue = nums[index];
        if (maxValue < nums[index])
            maxValue = nums[index];

        dfs(nums, index + 1, minValue, maxValue);
    }
};