#include <algorithm>
#include <string>
#include <vector>

class Solution {
  public:
    std::vector<int> survivedRobotsHealths(std::vector<int> &positions,
                                           std::vector<int> &healths,
                                           std::string directions) {
        std::vector<int> order;

        for (int i = 0; i < positions.size(); i++)
            order.push_back(i);

        std::sort(order.begin(), order.end(),
                  [&](int x, int y) { return positions[x] < positions[y]; });

        std::vector<int> L, R;
        for (int i = 0; i < positions.size(); i++) {
            int idx = order[i];
            if (directions[idx] == 'R') {
                R.push_back(idx);
            } else {
                bool win = true;
                while (!R.empty() && win) {
                    if (healths[R.back()] > healths[idx]) {
                        healths[R.back()]--;
                        win = false;
                    } else if (healths[R.back()] == healths[idx]) {
                        R.pop_back();
                        win = false;
                    } else {
                        R.pop_back();
                        healths[idx]--;
                    }
                }
                if (win)
                    L.push_back(idx);
            }
        }

        std::vector<int> rem;
        for (int x : L)
            rem.push_back(x);
        for (int x : R)
            rem.push_back(x);
        std::sort(rem.begin(), rem.end());

        std::vector<int> ans;
        for (int x : rem)
            ans.push_back(healths[x]);
        return ans;
    }
};