#include <unordered_map>
#include <vector>

class Solution {
  public:
    int minimumRounds(std::vector<int> &tasks) {
        int res = 0;
        std::unordered_map<int, int> um;

        for (const auto task : tasks) {
            ++um[task];
        }

        for (const auto [_, cnt] : um) {
            if (cnt % 3 == 0) {
                res += cnt / 3;
            } else if (cnt == 1) {
                return -1;
            } else {
                res += cnt / 3 + 1;
            }
        }

        return res;
    }
};