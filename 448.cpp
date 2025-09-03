#include <vector>

class Solution {
  public:
    std::vector<int> findDisappearedNumbers(std::vector<int> &nums) {
        std::vector<int> res;

        for (auto &iter : nums) {
            nums[(iter - 1) % nums.size()] += nums.size();
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= nums.size())
                res.push_back(i + 1);
        }

        return res;
    }
};