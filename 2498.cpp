#include <vector>

class Solution {
  public:
    int maxJump(std::vector<int> &stones) {
        int res = stones[1] - stones[0];
        for (int i = 2; i < stones.size(); i++) {
            res = std::max(res, stones[i] - stones[i - 2]);
        }
        return res;
    }
};