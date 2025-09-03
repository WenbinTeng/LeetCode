#include <unordered_set>
#include <vector>

class Solution {
  public:
    int minimumOperations(std::vector<int> &nums) {
        std::unordered_set<int> us;

        for (const auto &num : nums) {
            if (num > 0) {
                us.insert(num);
            }
        }

        return us.size();
    }
};