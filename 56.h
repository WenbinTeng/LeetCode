#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>> res;

        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b){return a[0] < b[0];});

        for (const auto& coor : intervals)
        {
            if (!res.empty() && res.back()[1] >= coor[0])
            {
                if (res.back()[1] < coor[1])
                {
                    res.back()[1] = coor[1];
                }
            }
            else
            {
                res.push_back(coor);
            }
        }

        return res;
    }
};