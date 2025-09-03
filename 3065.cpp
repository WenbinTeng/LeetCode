#include <vector>

class Solution {
  public:
    int minOperations(std::vector<int> &nums, int k) {
        int res = 0;

        for (auto num : nums)
            if (num < k)
                res++;

        return res;
    }
};