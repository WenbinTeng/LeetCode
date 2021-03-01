#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.empty())
        {
            if (nums2.size() % 2 == 0)
            {
                return (double)(nums2.at(nums2.size() / 2 - 1) + nums2.at(nums2.size() / 2)) / 2;
            }
            else
            {
                return nums2.at(nums2.size() / 2);
            }
        }
        if (nums2.empty())
        {
            if (nums1.size() % 2 == 0)
            {
                return (double)(nums1.at(nums1.size() / 2 - 1) + nums1.at(nums1.size() / 2)) / 2;
            }
            else
            {
                return nums1.at(nums1.size() / 2);
            }
        }

        auto iter1 = nums1.begin();
        auto iter2 = nums2.begin();
        std::vector<int> buff = {};
        int halfSize = (nums1.size() + nums2.size()) / 2;
        int i;
        for (i = 0; i <= halfSize && iter1 != nums1.end() && iter2 != nums2.end(); i++)
        {
            buff.push_back(*iter1 <= *iter2 ? *(iter1++) : *(iter2++));
        }
        if (iter1 == nums1.end())
        {
            while (i++ <= halfSize)
            {
                buff.push_back(*(iter2++));
            }
        }
        if (iter2 == nums2.end())
        {
            while (i++ <= halfSize)
            {
                buff.push_back(*(iter1++));
            }
        }
        if ((nums1.size() + nums2.size()) % 2 == 0)
        {
            return (double)(buff.back() + *(buff.end() - 2)) / 2;
        }
        else
        {
            return buff.back();
        }
        
        return 0;
    }
};