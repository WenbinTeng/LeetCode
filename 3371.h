#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int getLargestOutlier(std::vector<int>& nums) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        std::unordered_map<int, int> numDict;

        for (auto n : nums) {
            numDict[n]++;
        }

        std::sort(nums.begin(), nums.end());

        for (int i = n - 1; i >= 0; i--) {
            int oddNum = nums[i];
            sum -= oddNum;
            numDict[oddNum]--;
            if ((sum % 2 == 0) && numDict[sum / 2]) {
                return oddNum;
            }
            numDict[oddNum]++;
            sum += oddNum;
        }

        return -1;
    }
};