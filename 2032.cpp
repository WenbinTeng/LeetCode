#include <unordered_set>
#include <vector>

class Solution {
  public:
    std::vector<int> twoOutOfThree(std::vector<int> &nums1,
                                   std::vector<int> &nums2,
                                   std::vector<int> &nums3) {
        std::vector<int> res;
        std::unordered_set<int> us1;
        std::unordered_set<int> us2;
        std::unordered_set<int> us3;

        for (const auto n : nums1)
            us1.insert(n);
        for (const auto n : nums2)
            us2.insert(n);
        for (const auto n : nums3)
            us3.insert(n);

        for (int i = 0; i <= 100; ++i) {
            int cnt = 0;

            if (us1.count(i))
                ++cnt;
            if (us2.count(i))
                ++cnt;
            if (us3.count(i))
                ++cnt;

            if (cnt >= 2)
                res.push_back(i);
        }

        return res;
    }
};