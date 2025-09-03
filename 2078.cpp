#include <vector>

class Solution {
  public:
    int maxDistance(std::vector<int> &colors) {
        int res = 0;

        for (int i = 0; i < colors.size(); ++i) {
            for (int j = i + 1; j < colors.size(); ++j) {
                if (colors[i] != colors[j]) {
                    res = std::max(res, j - i);
                }
            }
        }

        return res;
    }
};