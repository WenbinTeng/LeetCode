#include <unordered_set>
#include <vector>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int> &nums, int k) {
        std::unordered_set<long long> us;

        for (int i = 0; i < nums.size() && i < k; ++i) {
            if (us.find(nums[i]) != us.end()) {
                return true;
            }
            us.insert(nums[i]);
        }

        for (int i = k; i < nums.size(); ++i) {
            if (us.find(nums[i]) != us.end()) {
                return true;
            }
            us.insert(nums[i]);
            us.erase(us.find(nums[i - k]));
        }

        return false;
    }
};