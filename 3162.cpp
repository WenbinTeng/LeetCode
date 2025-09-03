#include <vector>

class Solution {
  public:
    int numberOfPairs(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
        int res = 0;

        for (int i = 0; i < nums1.size(); i++)
            for (int j = 0; j < nums2.size(); j++)
                if (nums1[i] % (nums2[j] * k) == 0)
                    res++;

        return res;
    }
};