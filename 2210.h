#include <vector>

class Solution {
public:
    int countHillValley(std::vector<int>& nums) {
        int res = 0;

        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1] || nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            {
                ++res;
            }
            else if (nums[i] == nums[i + 1])
            {
                int j = i + 2;
                while (j < nums.size() && nums[j] == nums[i]) ++j;
                if (j == nums.size())
                {
                    break;
                }
                else
                {
                    if (nums[i] < nums[i - 1] && nums[i] < nums[j] || nums[i] > nums[i - 1] && nums[i] > nums[j])
                    {
                        ++res;
                    }
                    i = j - 1;
                }
            }
        }

        return res;
    }
};