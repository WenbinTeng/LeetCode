#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    long long numberOfPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        long long res = 0;
        int max = *std::max_element(nums1.begin(), nums1.end());
        std::unordered_map<int, int> dict1;
        std::unordered_map<int, int> dict2;

        for (auto num : nums1) {
            dict1[num]++;   
        }
        for (auto num : nums2) {
            dict2[num]++;
        }

        for (auto &[a, cnt] : dict2)
            for (int b = a * k; b <= max; b += a * k)
                if (dict1.count(b))
                    res += (long long)dict1[b] * cnt;

        return res;
    }
};