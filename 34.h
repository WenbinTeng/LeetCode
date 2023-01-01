#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target) {
        int n = nums.size() - 1;
        int prev = -1;
        int next = -1;
        int curr = binarySearch(nums, 0, nums.size() - 1, target);

        if (curr == -1)
            return {-1, -1};

        prev = curr;
        next = curr;

        while (--prev >= 0 && nums[prev] == nums[curr])
            ;
        while (++next <= n && nums[next] == nums[curr])
            ;

        return {prev + 1, next - 1};
    }

private:
    int binarySearch(std::vector<int> &nums, int l, int r, int target) {
        return l > r ? -1 : nums[(l + r) / 2] == target ? (l + r) / 2
                                                        : std::max(binarySearch(nums, l, (l + r) / 2 - 1, target), binarySearch(nums, (l + r) / 2 + 1, r, target));
    }
};