#include <unordered_map>
#include <vector>

class Solution {
public:
    int findShortestSubArray(std::vector<int> &nums) {
        std::unordered_map<int, std::vector<int>> um;
        int res = 0;
        int deg = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (um.find(nums[i]) == um.end()) {
                um[nums[i]] = std::vector<int>(3, 0);
                um[nums[i]][0] = 1;
                um[nums[i]][1] = i;
                um[nums[i]][2] = i;
            } else {
                um[nums[i]][0] += 1;
                um[nums[i]][2] = i;
            }
        }

        for (const auto &[idx, vec] : um) {
            if (deg < vec[0]) {
                deg = vec[0];
                res = vec[2] - vec[1] + 1;
            }
            if (deg == vec[0]) {
                res = std::min(res, vec[2] - vec[1] + 1);
            }
        }

        return res;
    }
};