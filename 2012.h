#include <vector>

class Solution {
public:
    int sumOfBeauties(std::vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        std::vector<int> state(n);

        int preMaxval = nums[0];
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > preMaxval) {
                state[i] = 1;
                preMaxval = nums[i];
            }
        }

        int sufMinVal = nums[n - 1];
        for (int i = n - 2; i > 0; i--) {
            if (state[i] && nums[i] < sufMinVal) {
                res += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                res += 1;
            }
            sufMinVal = std::min(sufMinVal, nums[i]);
        }

        return res;
    }
};