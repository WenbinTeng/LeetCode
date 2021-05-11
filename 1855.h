#include <vector>

class Solution {
public:
    int maxDistance(std::vector<int>& nums1, std::vector<int>& nums2) {
        int res = 0;
        int ptr = -1;
        
        for (int i = 0; i < nums1.size(); ++i) {
            while (ptr + 1 < nums2.size() && nums1[i] <= nums2[ptr + 1])
            {
                ++ptr;
            }
            res = max(res, ptr - i);
        }

        return res;
    }
};