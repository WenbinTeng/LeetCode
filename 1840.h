#include <vector>
#include <algorithm>

class Solution {
public:
    int maxBuilding(int n, std::vector<std::vector<int>>& restrictions) {
        if (restrictions.empty()) return n - 1;

        int res = 0;
        std::vector<int> l(restrictions.size());
        std::vector<int> r(restrictions.size());

        std::sort(restrictions.begin(), restrictions.end());
        
        l[0] = std::min(restrictions[0][1], restrictions[0][0] - 1);
        for (int i = 1; i < restrictions.size(); ++i) {
            int left = l[i - 1];
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            l[i] = std::min(restrictions[i][1], left + dist);
        }

        r[restrictions.size() - 1] = restrictions[restrictions.size() - 1][1];
        for (int i = restrictions.size() - 2; i >= 0; --i) {
            int right = r[i + 1];
            int dist = restrictions[i + 1][0] - restrictions[i][0];
            r[i] = std::min(restrictions[i][1], right + dist);
        }

        for (int i = 0; i < restrictions.size() - 1; ++i) {
            int lh = std::min(l[i], r[i]);
            int rh = std::min(l[i + 1], r[i + 1]);
            int dist = restrictions[i + 1][0] - restrictions[i][0];
            res = std::max(res, (lh + rh + dist) / 2);
        }
        
        return std::max(res, n - restrictions[restrictions.size() - 1][0] + std::min(l[restrictions.size() - 1], r[restrictions.size() - 1]));
    }
};