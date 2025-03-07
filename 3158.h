#include <vector>
#include <unordered_set>

class Solution {
public:
    int duplicateNumbersXOR(std::vector<int>& nums) {
        int res = 0;
        std::unordered_set<int> dict;

        for (int num : nums) {
            if (dict.count(num)) {
                res ^= num;
            } else {
                dict.emplace(num);
            }
        }

        return res;
    }
};