#include <vector>

class Solution {
  public:
    int trap(std::vector<int> &height) {
        int res = 0;

        for (int i = 1, n = height.size() - 1; i < n; i++) {
            int maxValue[2] = {0, 0};
            int maxIndex[2] = {i, i};

            for (; maxIndex[0] >= 0; maxIndex[0]--)
                maxValue[0] = std::max(maxValue[0], height[maxIndex[0]]);
            for (; maxIndex[1] <= n; maxIndex[1]++)
                maxValue[1] = std::max(maxValue[1], height[maxIndex[1]]);

            res += std::min(maxValue[0], maxValue[1]) - height[i];
        }

        return res;
    }
};