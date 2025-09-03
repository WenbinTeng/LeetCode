#include <unordered_set>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> findDifference(std::vector<int> &nums1,
                                                 std::vector<int> &nums2) {
        std::vector<std::vector<int>> res(2);
        std::unordered_set<int> us1;
        std::unordered_set<int> us2;

        for (const auto num1 : nums1) {
            us1.insert(num1);
        }

        for (const auto num2 : nums2) {
            us2.insert(num2);
        }

        for (const auto num1 : us1) {
            if (!us2.count(num1)) {
                res[0].push_back(num1);
            }
        }

        for (const auto num2 : us2) {
            if (!us1.count(num2)) {
                res[1].push_back(num2);
            }
        }

        return res;
    }
};