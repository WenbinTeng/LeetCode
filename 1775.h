#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    int minOperations(std::vector<int> &nums1, std::vector<int> &nums2) {
        if (nums1.size() > nums2.size() * 6)
            return -1;
        if (nums2.size() > nums1.size() * 6)
            return -1;

        int res = 0;
        int s1 = std::accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = std::accumulate(nums2.begin(), nums2.end(), 0);

        if (s1 > s2) {
            std::swap(s1, s2);
            std::swap(nums1, nums2);
        }

        std::sort(nums1.begin(), nums1.end(), std::less<int>());
        std::sort(nums2.begin(), nums2.end(), std::greater<int>());

        for (int i1 = 0, i2 = 0, n1 = nums1.size(), n2 = nums2.size(); (i1 < n1 || i2 < n2) && s1 < s2;) {
            int delta1 = i1 < n1 ? 6 - nums1[i1] : 0;
            int delta2 = i2 < n2 ? nums2[i2] - 1 : 0;

            if (i1 < n1 && delta1 >= delta2) {
                s1 += delta1;
                ++i1;
                ++res;
                continue;
            }
            if (i2 < n2 && delta1 <= delta2) {
                s2 -= delta2;
                ++i2;
                ++res;
                continue;
            }
        }

        return res;
    }
};