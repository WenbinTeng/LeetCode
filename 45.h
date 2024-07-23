#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int res = 0;
        int pos = nums.size() - 1;

        while (pos > 0) {
            for (int i = 0; i < nums.size(); i++) {
                if (pos <= i + nums[i]) {
                    pos = i;
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};