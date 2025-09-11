#include <vector>

class Solution {
  public:
    int trap(std::vector<int> &height) {
        const int n = height.size();
        int res = 0;
        std::vector<int> leftMax(n, 0);
        std::vector<int> rightMax(n, 0);

        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = std::max(leftMax[i - 1], height[i]);
        }

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = std::max(rightMax[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++) {
            res += (std::min(leftMax[i], rightMax[i]) - height[i]);
        }

        return res;
    }
};