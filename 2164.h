#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> sortEvenOdd(std::vector<int> &nums) {
        std::vector<int> u;
        std::vector<int> v;

        for (int i = 0; i < nums.size(); i += 2) {
            u.push_back(nums[i]);
        }
        for (int i = 1; i < nums.size(); i += 2) {
            v.push_back(nums[i]);
        }

        std::sort(v.begin(), v.end(), std::greater<int>());
        std::sort(u.begin(), u.end(), std::less<int>());

        for (int i = 0; i < nums.size() / 2; ++i) {
            nums[2 * i] = u[i];
            nums[2 * i + 1] = v[i];
        }

        if (nums.size() % 2 == 1) {
            nums.back() = u.back();
        }

        return nums;
    }
};