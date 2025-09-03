#include <unordered_set>
#include <vector>

class Solution {
  public:
    bool containsDuplicate(std::vector<int> &nums) {
        std::unordered_set<int> us;

        for (const auto &num : nums) {
            if (us.find(num) != us.end()) {
                return true;
            }
            us.insert(num);
        }

        return false;
    }
};