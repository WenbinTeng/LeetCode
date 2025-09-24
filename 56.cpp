#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>>
    merge(std::vector<std::vector<int>> &intervals) {
        std::vector<std::vector<int>> res;

        std::sort(intervals.begin(), intervals.end());

        for (auto interval : intervals) {
            int l = interval[0];
            int r = interval[1];
            if (res.empty() || res.back()[1] < l) {
                res.push_back(interval);
            } else {
                res.back()[1] = std::max(res.back()[1], r);
            }
        }

        return res;
    }
};