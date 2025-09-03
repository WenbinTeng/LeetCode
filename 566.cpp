#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>>
    matrixReshape(std::vector<std::vector<int>> &nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c)
            return nums;
        std::vector<std::vector<int>> res(r, std::vector<int>(c));
        for (int i = 0; i < m * n; i++) {
            res[i / c][i % c] = nums[i / n][i % n];
        }

        return res;
    }
};