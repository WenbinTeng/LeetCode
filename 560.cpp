#include <unordered_map>
#include <vector>

class Solution {
  public:
    int subarraySum(std::vector<int> &nums, int k) {
        const int n = nums.size();
        int res = 0;
        std::vector<int> prevSum(n + 1);
        std::unordered_map<int, int> dict;

        prevSum[0] = 0;
        for (int i = 0; i < n; i++) {
            prevSum[i + 1] = prevSum[i] + nums[i];
        }

        dict[0] = 1;
        for (int i = 0; i < n; i++) {
            res += dict[prevSum[i + 1] - k];
            dict[prevSum[i + 1]]++;
        }

        return res;
    }
};