#include <map>
#include <vector>

class Solution {
  public:
    int maxDistinctElements(std::vector<int> &nums, int k) {
        int res = 0;
        int min = -INT_MAX;
        std::map<int, int> dict;

        for (auto num : nums) {
            dict[num]++;
        }

        for (auto &[num, cnt] : dict) {
            int lower = num - k;
            int upper = num + k;
            if (min < lower) {
                min = std::min(lower + cnt - 1, upper);
                res += min - lower + 1;
            } else if (min <= upper) {
                int prevMin = min;
                min = std::min(prevMin + cnt, upper);
                res += min - prevMin;
            }
        }

        return res;
    }
};