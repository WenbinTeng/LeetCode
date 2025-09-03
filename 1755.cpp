#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
  public:
    int minAbsDifference(std::vector<int> &nums, int goal) {
        res = std::abs(goal);
        std::vector<int> sums;
        calCombinationSum(nums, sums, 0, 0);
        std::sort(sums.begin(), sums.end());
        getMinAbsDifference(nums, sums, (nums.size() + 1) / 2, 0, goal);
        return res;
    }

  private:
    int res;

    void calCombinationSum(std::vector<int> &nums, std::vector<int> &sums,
                           int index, int sum) {
        if (index == (nums.size() + 1) / 2) {
            sums.push_back(sum);
            return;
        }

        calCombinationSum(nums, sums, index + 1, sum);
        calCombinationSum(nums, sums, index + 1, sum + nums[index]);
    }

    void getMinAbsDifference(std::vector<int> &nums, std::vector<int> &sums,
                             int index, int sum, int goal) {
        if (res == 0)
            return;

        if (index == nums.size()) {
            int n = sums.size() - 1;
            int l;
            int r;
            for (l = 0, r = n; l < r;) {
                int mid = (l + r) / 2;

                if (sums[mid] + sum == goal) {
                    res = 0;
                    return;
                } else if (sums[mid] + sum < goal) {
                    l = mid + 1;
                } else if (sums[mid] + sum > goal) {
                    r = mid - 1;
                }
            }

            res = std::min(res, std::abs(sums[(l + r) / 2] + sum - goal));
            if (l > 0)
                res = std::min(res, std::abs(sums[l - 1] + sum - goal));
            if (r < n)
                res = std::min(res, std::abs(sums[r + 1] + sum - goal));

            return;
        }
        getMinAbsDifference(nums, sums, index + 1, sum, goal);
        getMinAbsDifference(nums, sums, index + 1, sum + nums[index], goal);
    }
};