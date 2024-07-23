#include <vector>
#include <unordered_map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int res = 0;
        int val = 0;
        std::unordered_map<int, int> count;

        for (const auto num : nums) {
            count[num]++;
            if (val < count[num]) {
                val = count[num];
                res = num;
            }
        }

        return res;
    }
};