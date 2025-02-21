#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findIntersectionValues(std::vector<int>& nums1, std::vector<int>& nums2) {
        int ans1 = 0;
        int ans2 = 0;
        std::unordered_map<int, int> dict1;
        std::unordered_map<int, int> dict2;

        for (auto num : nums1)
            dict1[num]++;
        for (auto num : nums2)
            dict2[num]++;
        
        for (auto num : nums1)
            if (dict2.count(num))
                ans1++;
        for (auto num : nums2)
            if (dict1.count(num))
                ans2++;
        
        return {ans1, ans2};
    }
};