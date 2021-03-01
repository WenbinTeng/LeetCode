#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        if (nums.size() <= 1) return;

        int large = -1;
        int small = -1;
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                small = i; break;
            }
        }

        if (small == -1) {std::reverse(nums.begin(), nums.end()); return;}

        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[small] < nums[i])
            {
                large = i; break;
            }
        }

        std::swap(nums[small], nums[large]);
        std::reverse(nums.begin() + small + 1, nums.end());

        return;
    }
};