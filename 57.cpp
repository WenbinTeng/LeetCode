#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>>
    insert(std::vector<std::vector<int>> &intervals,
           std::vector<int> &newInterval) {
        std::vector<std::vector<int>> res;
        bool placed = false;

        std::sort(intervals.begin(), intervals.end(),
                  [](std::vector<int> &a, std::vector<int> &b) {
                      return a[0] < b[0];
                  });

        int i = 0;
        while (i < intervals.size() && !placed) {
            if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
                i++;
            } else if (intervals[i][0] > newInterval[1]) {
                res.push_back(newInterval);
                placed = true;
                break;
            } else {
                newInterval[0] = intervals[i][0] < newInterval[0]
                                     ? intervals[i][0]
                                     : newInterval[0];

                for (int j = i; j < intervals.size(); j++) {
                    if (intervals[j][0] > newInterval[1]) {
                        res.push_back(newInterval);
                        placed = true;
                        i = j;
                        break;
                    }
                    if (intervals[j][1] > newInterval[1]) {
                        res.push_back({newInterval[0], intervals[j][1]});
                        placed = true;
                        i = j + 1;
                        break;
                    }
                }

                if (!placed) {
                    i = intervals.size();
                    break;
                }
            }
        }

        while (i < intervals.size()) {
            res.push_back(intervals[i++]);
        }

        if (!placed) {
            res.push_back(newInterval);
        }

        return res;
    }
};