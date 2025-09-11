#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        const int n = nums.size();
        int res = 0;
        int prevSum = 0;
        std::unordered_map<int, int> dict;

        dict[0] = 1;
        for (int i = 0; i < n; i++) {
            prevSum += nums[i];
            if (dict.count(prevSum - k)) {
                res += dict[prevSum - k];
            }
            dict[prevSum]++;
        }

        return res;
    }
};