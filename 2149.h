#include <vector>

class Solution {
public:
    std::vector<int> rearrangeArray(std::vector<int> &nums) {
        std::vector<int> res;
        int posIndex = 0;
        int negIndex = 0;

        while (true) {
            while (posIndex < nums.size() && nums[posIndex] < 0)
                ++posIndex;
            while (negIndex < nums.size() && nums[negIndex] > 0)
                ++negIndex;

            if (negIndex >= nums.size() || posIndex >= nums.size())
                break;

            res.push_back(nums[posIndex++]);
            res.push_back(nums[negIndex++]);
        }

        return res;
    }
};