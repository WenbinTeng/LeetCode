#include <algorithm>
#include <vector>

class Solution {
  public:
    int heightChecker(std::vector<int> &heights) {
        int res = 0;
        std::vector<int> expected(heights);
        std::sort(expected.begin(), expected.end());

        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != expected[i]) {
                ++res;
            }
        }

        return res;
    }
};