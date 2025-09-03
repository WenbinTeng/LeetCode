#include <unordered_map>
#include <vector>

class Solution {
  public:
    bool isPossibleToSplit(std::vector<int> &nums) {
        std::unordered_map<int, int> dict;

        for (auto &num : nums) {
            dict[num]++;
            if (dict[num] > 2) {
                return false;
            }
        }

        return true;
    }
};