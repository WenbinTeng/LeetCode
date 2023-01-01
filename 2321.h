#include <vector>

class Solution {
public:
    int maximumsSplicedArray(std::vector<int> &nums1, std::vector<int> &nums2) {
        return std::max(maxDiffArray(nums1, nums2), maxDiffArray(nums2, nums1));
    }

private:
    int maxDiffArray(std::vector<int> &nums1, std::vector<int> &nums2) {
        int sum1 = 0;
        int sumMax = 0;

        for (int i = 0, s = 0; i < nums1.size(); ++i) {
            sum1 += nums1[i];
            s = std::max(s + nums2[i] - nums1[i], 0);
            sumMax = std::max(sumMax, s);
        }

        return sum1 + sumMax;
    }
};