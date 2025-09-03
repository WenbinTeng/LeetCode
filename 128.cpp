#include <unordered_set>
#include <vector>

class Solution {
  public:
    int longestConsecutive(std::vector<int> &nums) {
        int res = 0;
        std::unordered_set<int> dict;

        for (auto num : nums) {
            dict.insert(num);
        }

        for (auto num : dict) {
            if (!dict.count(num - 1)) {
                int currNum = num;
                int currLen = 1;
                while (dict.count(currNum + 1)) {
                    currNum++;
                    currLen++;
                }
                res = std::max(res, currLen);
            }
        }

        return res;
    }
};