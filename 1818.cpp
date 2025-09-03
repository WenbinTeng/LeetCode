#include <algorithm>
#include <vector>

class Solution {
  public:
    int minAbsoluteSumDiff(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::vector<int> absDiff(nums1.size());

        for (int i = 0; i < nums1.size(); ++i) {
            absDiff[i] = std::abs(nums1[i] - nums2[i]);
        }

        auto maxIter = std::max_element(absDiff.begin(), absDiff.end());

        int maxValue = *maxIter;
        int maxIndex = std::distance(absDiff.begin(), maxIter);

        if (*maxIter == 0)
            return 0;

        int minDiff = maxValue;
        int curDiff = maxValue;

        for (int i = 0; i < nums1.size(); ++i) {
            curDiff = std::abs(nums1[i] - nums2[maxIndex]);
            minDiff = std::min(minDiff, curDiff);

            if (minDiff == 0)
                break;
        }

        absDiff[maxIndex] = minDiff;

        int res = 0;

        for (const auto &diff : absDiff) {
            res = (res + diff) % (int)(1e+9 + 7);
        }

        return res;
    }
};