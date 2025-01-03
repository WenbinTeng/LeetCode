#include <vector>
#include <unordered_set>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        std::unordered_set<int> dict;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] <= k && nums[i] >= 1) {
                dict.insert(nums[i]);
            }
            if (dict.size() == k) {
                return nums.size() - i;
            }
        }

        return nums.size();
    }
};