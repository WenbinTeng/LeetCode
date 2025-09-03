#include <unordered_map>
#include <vector>

class Solution {
  public:
    int singleNumber(std::vector<int> &nums) {
        std::unordered_map<int, int> um;

        for (const auto &num : nums) {
            ++um[num];
        }

        for (const auto &[k, v] : um) {
            if (v == 1)
                return k;
        }

        return 0;
    }
};