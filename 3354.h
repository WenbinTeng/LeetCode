#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int countValidSelections(std::vector<int>& nums) {
        int res = 0;
        int lsum = 0;
        int rsum = std::accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < nums.size(); i++) {
            lsum += nums[i];
            rsum -= nums[i];
            if (nums[i] == 0) {
                if (lsum == rsum)
                    res += 2;
                else if (std::abs(lsum - rsum) == 1)
                    res += 1;
            }
        }

        return res;
    }
};