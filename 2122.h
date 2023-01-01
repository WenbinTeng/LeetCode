#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> recoverArray(std::vector<int> &nums) {
        std::unordered_map<int, int> um;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            ++um[nums[i]];
        }

        for (int i = nums.size() - 2; i >= (nums.size() - 1) / 2; --i) {
            int kk = nums.back() - nums[i];

            if (kk == 0 || kk % 2 == 1)
                continue;

            bool flag = true;
            std::vector<int> tmpVec;
            std::unordered_map<int, int> tmpMap = um;

            for (auto num : nums) {
                if (tmpMap[num] == 0) {
                    continue;
                }
                if (tmpMap[num] > tmpMap[num + kk]) {
                    flag = false;
                    break;
                }

                for (int j = 0; j < tmpMap[num]; ++j) {
                    tmpVec.push_back(num + kk / 2);
                }

                tmpMap[num + kk] -= tmpMap[num];
                tmpMap[num] = 0;
            }

            if (flag)
                return tmpVec;
        }

        return {};
    }
};