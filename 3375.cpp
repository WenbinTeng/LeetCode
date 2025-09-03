#include <map>
#include <vector>

class Solution {
  public:
    int minOperations(std::vector<int> &nums, int k) {
        int res = 0;
        std::map<int, int> dict;

        for (auto num : nums) {
            dict[num]++;
        }

        for (auto &[num, cnt] : dict) {
            if (num < k)
                return -1;
            else if (num > k)
                res++;
        }

        return res;
    }
};