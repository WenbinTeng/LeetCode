#include <vector>
#include <unordered_map>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        const int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[nums[i] - 1], nums[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};