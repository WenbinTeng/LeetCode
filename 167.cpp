#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int> &numbers, int target) {
        std::unordered_map<int, int> um;

        for (int i = 0; i < numbers.size(); i++) {
            um[numbers[i]] = i;
        }

        for (int i = 0; i < numbers.size(); i++) {
            if (um.count(target - numbers[i])) {
                int j = um[target - numbers[i]];
                if (i != j) {
                    return {std::min(i, j) + 1, std::max(i, j) + 1};
                }
            }
        }

        return {};
    }
};