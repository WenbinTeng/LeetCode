#include <vector>

class Solution {
public:
    std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        std::vector<int> res(n);

        for (auto num : nums) {
            if (num % 2 == 0) {
                res[i] = num;
                i += 2;
            }
        }

        i = 1;
        for (auto num : nums) {
            if (num % 2 == 1) {
                res[i] = num;
                i += 2;
            }
        }

        return res;
    }
};