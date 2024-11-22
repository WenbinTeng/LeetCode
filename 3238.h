#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    int winningPlayerCount(int n, std::vector<std::vector<int>>& pick) {
        std::set<int> winSet;
        std::vector<std::pair<int, int>> pickRec(n, {-1, 0});

        std::sort(pick.begin(), pick.end(), [](std::vector<int> &a, std::vector<int> &b){
            return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
        });

        for (auto p : pick) {
            int x = p[0];
            int y = p[1];
            auto [lastColor, lastCount] = pickRec[x];
            if (y != lastColor) {
                pickRec[x] = {y, 1};
            } else {
                pickRec[x] = {y, lastCount + 1};
            }
            if (pickRec[x].second > x) {
                winSet.insert (x);
            }
        }

        return winSet.size();
    }
};