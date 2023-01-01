#include <vector>

class Solution {
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
        if (n == 0)
            return;

        int i1 = m - 1;
        int i2 = n - 1;

        for (int index = m + n - 1; index >= 0 && i1 >= 0 && i2 >= 0; --index) {
            nums1[index] = nums1[i1] > nums2[i2] ? nums1[i1--] : nums2[i2--];
        }

        while (i2 >= 0) {
            nums1[i2] = nums2[i2];
            --i2;
        }
    }
};