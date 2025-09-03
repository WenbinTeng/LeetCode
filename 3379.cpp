#include <vector>

class Solution {
  public:
    std::vector<int> constructTransformedArray(std::vector<int> &nums) {
        std::vector<int> res;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            int step = (i + nums[i] + n) % n;
            while (step < 0)
                step = (step + n) % n;
            res.push_back(nums[step]);
        }

        return res;
    }
};