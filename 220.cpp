#include <set>
#include <vector>

class Solution {
  public:
    bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int k, int t) {
        std::set<long long> s;

        for (int i = 0; i < nums.size() && i < k; ++i) {
            auto l = s.lower_bound((long long)nums[i] - t);
            if (l != s.end() && *l <= (long long)nums[i] + t) {
                return true;
            }
            s.insert(nums[i]);
        }

        for (int i = k; i < nums.size(); i++) {
            auto l = s.lower_bound((long long)nums[i] - t);
            if (l != s.end() && *l <= (long long)nums[i] + t) {
                return true;
            }
            s.insert(nums[i]);
            s.erase(s.find(nums[i - k]));
        }
        return false;
    }
};