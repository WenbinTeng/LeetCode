#include <set>
#include <vector>

class Solution {
  public:
    int minCostToMoveChips(std::vector<int> &position) {
        int res = INT_MAX;
        std::set<int> s;

        for (auto &p : position)
            s.insert(p);

        for (auto p : s) {
            int cost = 0;
            for (int i = 0; i < position.size(); i++) {
                cost += (position[i] - p) & 1;
            }
            res = std::min(res, cost);
        }

        return res;
    }
};