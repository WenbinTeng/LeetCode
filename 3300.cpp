#include <algorithm>
#include <vector>

class Solution {
  public:
    int minElement(std::vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = accumulateDigits(nums[i]);
        }
        return *std::min_element(nums.begin(), nums.end());
    }

  private:
    int accumulateDigits(int num) {
        int ret = 0;
        while (num) {
            ret += num % 10;
            num /= 10;
        }
        return ret;
    }
};