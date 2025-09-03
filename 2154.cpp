#include <set>
#include <vector>

class Solution {
  public:
    int findFinalValue(std::vector<int> &nums, int original) {
        std::set<int> s;

        for (const auto num : nums) {
            s.insert(num);
        }

        while (true) {
            if (!s.count(original)) {
                return original;
            } else {
                original *= 2;
            }
        }

        return original;
    }
};