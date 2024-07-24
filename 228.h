#include <cstdlib>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        std::vector<std::string> res;
        int left = 0;
        int right = 1;

        while (right <= nums.size()) {
            if (right == nums.size() || (long)nums[right] - (long)nums[right - 1] > 1) {
                if (right - left == 1) {
                    char buff[12];
                    sprintf(buff, "%d", nums[left]);
                    res.push_back(buff);
                } else {
                    std::string s = "";
                    char buff[12];
                    sprintf(buff, "%d", nums[left]);
                    s += buff;
                    s += "->";
                    sprintf(buff, "%d", nums[right - 1]);
                    s += buff;
                    res.push_back(s);
                }
                left = right;
            }
            right++;
        }

        return res;
    }
};