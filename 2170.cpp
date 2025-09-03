#include <unordered_map>
#include <vector>

class Solution {
  public:
    int minimumOperations(std::vector<int> &nums) {
        int res;
        int maxnum1 = 0;
        int maxnum2 = 0;
        int maxVal1 = 0;
        int maxVal2 = 0;
        std::unordered_map<int, int> um1;
        std::unordered_map<int, int> um2;

        for (int i = 0; i < nums.size(); i += 2) {
            ++um1[nums[i]];
        }

        for (int i = 1; i < nums.size(); i += 2) {
            ++um2[nums[i]];
        }

        for (const auto &[k, v] : um1) {
            if (maxVal1 < v) {
                maxVal1 = v;
                maxnum1 = k;
            }
        }

        for (const auto &[k, v] : um2) {
            if (maxVal2 < v && maxnum1 != k) {
                maxVal2 = v;
                maxnum2 = k;
            }
        }

        res = nums.size() - maxVal1 - maxVal2;
        maxnum1 = 0;
        maxnum2 = 0;
        maxVal1 = 0;
        maxVal2 = 0;

        for (const auto &[k, v] : um2) {
            if (maxVal2 < v) {
                maxVal2 = v;
                maxnum2 = k;
            }
        }

        for (const auto &[k, v] : um1) {
            if (maxVal1 < v && maxnum2 != k) {
                maxVal1 = v;
                maxnum1 = k;
            }
        }

        res = std::min(res, (int)nums.size() - maxVal1 - maxVal2);

        return res;
    }
};