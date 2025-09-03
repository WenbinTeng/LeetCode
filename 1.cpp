#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> hashTable;

        for (int i = 0; i < nums.size(); i++) {
            auto iter = hashTable.find(target - nums[i]);
            if (iter == hashTable.end()) {
                hashTable[nums[i]] = i;
            } else {
                return {iter->second, i};
            }
        }

        return {};
    }
};