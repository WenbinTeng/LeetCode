#include <vector>

class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        int offset = 0;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                offset = i; break;
            }
        }

        for (int n = nums.size(), l = offset, r = offset + n - 1; l <= r;)
        {
            int mid = (l + r) / 2;

            if (nums[mid % n] == target) return true;
            else if (nums[mid % n] < target) l = mid + 1;
            else if (nums[mid % n] > target) r = mid - 1;
        }

        return false;
    }
};