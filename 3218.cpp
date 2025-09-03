#include <algorithm>
#include <vector>

class Solution {
  public:
    int minimumCost(int m, int n, std::vector<int> &horizontalCut,
                    std::vector<int> &verticalCut) {
        int res = 0;
        std::vector<std::pair<int, int>> cuts;

        for (auto cut : horizontalCut) {
            cuts.push_back({cut, 0});
        }
        for (auto cut : verticalCut) {
            cuts.push_back({cut, 1});
        }

        std::sort(cuts.begin(), cuts.end(),
                  std::greater<std::pair<int, int>>());

        int horCnt = 1;
        int verCnt = 1;

        for (int i = 0; i < cuts.size(); i++) {
            auto [cost, type] = cuts[i];
            if (type == 0) {
                res += verCnt * cost;
                horCnt++;
            } else {
                res += horCnt * cost;
                verCnt++;
            }
        }

        return res;
    }
};