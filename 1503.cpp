#include <algorithm>
#include <vector>

class Solution {
  public:
    int getLastMoment(int n, std::vector<int> &left, std::vector<int> &right) {
        int res = 0;

        for (auto pos : left) {
            res = std::max(res, pos);
        }
        for (auto pos : right) {
            res = std::max(res, n - pos);
        }

        return res;
    }
};