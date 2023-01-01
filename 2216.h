#include <vector>

class Solution {
public:
    int minDeletion(std::vector<int> &nums) {
        int res = 0;

        int i;
        int j;
        for (i = 0; i < nums.size(); i += 2) {
            for (j = i + 1; j < nums.size() && nums[i] == nums[j]; ++j)
                ;
            res += j - i - 1;
            i = j - 1;
        }

        if ((nums.size() - res) % 2 == 1)
            ++res;

        return res;
    }
};