#include <algorithm>
#include <map>
#include <set>
#include <vector>

class Solution {
public:
    std::vector<int> minInterval(std::vector<std::vector<int>> &intervals, std::vector<int> &queries) {
        std::vector<int> res;
        std::map<int, int> m;
        std::set<std::pair<int, int>> s;

        for (const auto &query : queries) {
            m.insert({query, -1});
        }

        std::sort(intervals.begin(), intervals.end());

        int index = -1;

        for (const auto &[q, i] : m) {
            while (index + 1 < intervals.size() && intervals[index + 1][0] <= q) {
                ++index;
                s.insert({intervals[index][1] - intervals[index][0] + 1, intervals[index][1]});
            }

            while (!s.empty() && s.begin()->second < q)
                s.erase(s.begin());

            if (!s.empty())
                m[q] = (*s.begin()).first;
        }

        for (const auto &query : queries) {
            res.push_back(m[query]);
        }

        return res;
    }
};