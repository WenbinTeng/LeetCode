#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if (nums.empty()) return 0;

        int n = nums.size() - 1;
        int small;
        int large;
        int middle;

        for (small = 0, large = n, middle = (small + large) / 2; small <= large;)
        {
            if (target == nums[middle]) return middle;
            if (target < nums[middle]) {large = middle - 1; middle = (small + large) / 2; continue;}
            if (target > nums[middle]) {small = middle + 1; middle = (small + large) / 2; continue;}
        }

        return target < nums[middle] ? middle : middle + 1;
    }
};