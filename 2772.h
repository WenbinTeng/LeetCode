#include <vector>

class Solution {
public:
    bool checkArray(std::vector<int> &nums, int k) {
        int n = nums.size();
        int sumDiff = 0;
        std::vector<int> diff(n + 1);
        
        for (int i = 0; i < n; i++) {
            sumDiff += diff[i];
            int x = nums[i];
            x += sumDiff;
            if (x == 0)
                continue;
            if (x < 0 || i + k > n)
                return false;
            sumDiff -= x;
            diff[i + k] += x;
        }

        return true;
    }
};
