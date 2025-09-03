#include <unordered_set>
#include <vector>

class Solution {
  public:
    int maxSum(std::vector<int> &nums) {
        int n = nums.size();
        int res = nums[0];

        for (int i = 0; i < n; i++) {
            int sum = nums[i];
            std::unordered_set<int> dict = {sum};
            for (int j = i + 1; j < n; j++) {
                int num = nums[j];
                if (dict.count(num))
                    continue;
                dict.insert(num);
                sum = std::max(sum, sum + num);
            }
            res = std::max(res, sum);
        }

        return res;
    }
};