#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> res;
        std::unordered_map<int, int> dict;

        for (auto num : nums1) {
            dict[num]++;
        }

        for (auto num : nums2) {
            if (dict[num] > 0) {
                dict[num]--;
                res.push_back(num);
            }
        }

        return res;
    }
};