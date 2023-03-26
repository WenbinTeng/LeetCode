#include <vector>
#include <unordered_set>

class Solution {
public:
    bool findSubarrays(std::vector<int>& nums) {
        std::unordered_set<int> us;

        for (int i = 1; i < nums.size(); ++i) {
            int sum = nums[i - 1] + nums[i];
            if (us.count(sum)) {
                return true;
            }
            us.insert(sum);
        }

        return false;
    }
};