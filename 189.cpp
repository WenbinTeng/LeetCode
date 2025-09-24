#include <numeric>
#include <vector>

class Solution {
  public:
    void rotate(std::vector<int> &nums, int k) {
        const int n = nums.size();
        k = k % n;
        int step = std::gcd(n, k);

        for (int i = 0; i < step; i++) {
            int currIndex = i;
            int prevNum = nums[i];
            do {
                int nextIndex = (currIndex + k) % n;
                std::swap(nums[nextIndex], prevNum);
                currIndex = nextIndex;
            } while (currIndex != i);
        }
    }
};