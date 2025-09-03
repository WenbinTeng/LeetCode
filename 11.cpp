#include <vector>

class Solution {
  public:
    int maxArea(std::vector<int> &height) {
        int i = 0, j = height.size() - 1;
        int maxVol = 0;

        while (i < j) {
            maxVol = std::max(maxVol, (j - i) * std::min(height[i], height[j]));

            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return maxVol;
    }
};