#include <vector>
#include <set>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums, int limit) {
        int res = 1;
        std::multiset<int> smallSet;
        std::multiset<int, std::greater<int>> bigSet;

        int left = 0;
        int right = 1;

        smallSet.insert(nums[0]);
        bigSet.insert(nums[0]);
        while (right < nums.size()) {
            smallSet.insert(nums[right]);
            bigSet.insert(nums[right]);
            int min = *smallSet.begin();
            int max = *bigSet.begin();
            while ((max - min > limit) && (left < right)) {
                smallSet.erase(smallSet.find(nums[left]));
                bigSet.erase(bigSet.find(nums[left]));
                min = *smallSet.begin();
                max = *bigSet.begin();
                left++;
            }
            res = std::max(res, right - left + 1);
            right++;
        }

        return res;
    }
};