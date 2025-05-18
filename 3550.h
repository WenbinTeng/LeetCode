#include <vector>

class Solution {
public:
    int smallestIndex(std::vector<int>& nums) {
        auto sumDigits = [](int num) -> int {
            int sum = 0;
            while (num) {
                sum += (num % 10);
                num /= 10;
            }
            return sum;
        };

        for (int i = 0; i < nums.size(); i++) {
            if (sumDigits(nums[i]) == i)
                return i;
        }

        return -1;
    }
};