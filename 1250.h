#include <vector>
#include <algorithm>

class Solution {
public:
    bool isGoodArray(std::vector<int>& nums) {
        int divisor = nums[0];

        for (int num : nums) {
            divisor = std::__gcd(divisor, num);
            if (divisor == 1) {
                break;
            }
        }
        
        return divisor == 1;
    }
};