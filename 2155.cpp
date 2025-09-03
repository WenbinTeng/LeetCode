#include <vector>

class Solution {
  public:
    std::vector<int> maxScoreIndices(std::vector<int> &nums) {
        std::vector<int> res;

        int maxScore = 0;
        int lScore = 0;
        int rScore = 0;

        for (const auto num : nums) {
            if (num == 1) {
                ++rScore;
            }
        }

        maxScore = rScore + lScore;
        res.push_back(0);

        for (int i = 1; i <= nums.size(); ++i) {
            if (nums[i - 1] == 1) {
                --rScore;
            } else {
                ++lScore;
            }

            if (maxScore < lScore + rScore) {
                maxScore = lScore + rScore;
                res.clear();
                res.push_back(i);
            } else if (maxScore == lScore + rScore) {
                res.push_back(i);
            }
        }

        return res;
    }
};