#include <vector>

class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    res++;
                }
            }
        }

        return res;
    }
};