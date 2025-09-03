#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<int> fullBloomFlowers(std::vector<std::vector<int>> &flowers,
                                      std::vector<int> &persons) {
        std::vector<int> res(persons.size());
        std::vector<std::pair<int, int>> interval;
        int cnt = 0;
        int inf = 1e+9;

        for (const auto &flower : flowers) {
            interval.push_back({flower[0], -inf});
            interval.push_back({flower[1], inf});
        }

        for (int i = 0; i < persons.size(); ++i) {
            interval.push_back({persons[i], i});
        }

        std::sort(interval.begin(), interval.end());

        for (const auto [_, person] : interval) {
            if (person == -inf) {
                ++cnt;
            } else if (person == inf) {
                --cnt;
            } else {
                res[person] = cnt;
            }
        }

        return res;
    }
};