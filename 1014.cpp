#include <vector>

class Solution {
  public:
    int maxScoreSightseeingPair(std::vector<int> &values) {
        int res = 0;
        int val = values[0] + 0;

        for (int j = 0; j < values.size(); j++) {
            res = std::max(res, val + values[j] - j);
            val = std::max(val, values[j] + j);
        }

        return res;
    }
};