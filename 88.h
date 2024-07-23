#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        } else if (m == 0) {
            nums1 = nums2;
            return;
        }

        int p = m + n - 1;
        m--;
        n--;

        while (p >= 0) {
            if (m < 0) {
                nums1[p--] = nums2[n--];
            } else if (n < 0) {
                break;
            } else {
                if (nums1[m] >= nums2[n]) {
                    nums1[p--] = nums1[m--];
                } else {
                    nums1[p--] = nums2[n--];
                }
            }
        }
    }
};