#include <vector>

class Solution {
  public:
    int getXORSum(std::vector<int> &arr1, std::vector<int> &arr2) {
        int res = 0;
        int sum = 0;

        for (const auto &ele : arr2) {
            sum ^= ele;
        }

        for (const auto &ele : arr1) {
            res ^= ele & sum;
        }

        return res;
    }
};