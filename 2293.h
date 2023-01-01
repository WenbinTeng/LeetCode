#include <vector>

class Solution {
public:
    int minMaxGame(std::vector<int> &nums) {
        std::vector<int> newNums;

        while (nums.size() > 1) {
            newNums = std::vector<int>(nums.size() / 2);

            for (int i = 0; i < newNums.size(); ++i) {
                if (i % 2 == 0) {
                    newNums[i] = std::min(nums[i * 2], nums[i * 2 + 1]);
                } else {
                    newNums[i] = std::max(nums[i * 2], nums[i * 2 + 1]);
                }
            }

            nums = newNums;
        }

        return nums.back();
    }
};