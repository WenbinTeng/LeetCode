#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        int i;
        int j;
        int temp;
        for (i = 0, j = 0; i < nums.size();)
        {
            for (temp = nums[j++] = nums[i++]; i < nums.size() && temp == nums[i]; i++);
        }
        return j;
    }
};