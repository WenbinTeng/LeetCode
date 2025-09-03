#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> answerQueries(std::vector<int> &nums,
                                   std::vector<int> &queries) {
        std::vector<int> res(queries.size());

        std::sort(nums.begin(), nums.end());

        for (int i = 0, f = 0; i < queries.size(); ++i) {
            for (int j = 0, s = 0; j < nums.size(); ++j) {
                s += nums[j];
                if (s > queries[i]) {
                    res[i] = j;
                    f = 1;
                    break;
                }
            }
            if (!f)
                res[i] = nums.size();
            f = 0;
        }

        return res;
    }
};