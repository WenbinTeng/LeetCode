#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums, std::vector<int>& numsDivide) {
        int g = numsDivide[0];

        for (int i = 1; i < numsDivide.size(); ++i)
        {
            g = std::__gcd(g, numsDivide[i]);
        }

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            if (g % nums[i] == 0) return i;
        }

        return -1;
    }
};