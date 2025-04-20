#include <vector>

class Solution {
public:
    int maximumPossibleSize(std::vector<int>& nums) {
        int res = 1;
        int prevMaxVal = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (prevMaxVal <= nums[i]) {
                prevMaxVal = nums[i];
                res++;
            }
        }

        return res;
    }
};