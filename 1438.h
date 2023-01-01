#include <set>
#include <vector>

class Solution {
public:
    int longestSubarray(std::vector<int> &nums, int limit) {
        int res = 0;
        std::multiset<int> window;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            window.insert(nums[r]);
            while (*window.rbegin() - *window.begin() > limit) {
                window.erase(window.find(nums[l++]));
            }
            res = std::max(res, r - l + 1);
        }

        return res;
    }
};