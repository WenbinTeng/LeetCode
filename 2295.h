#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<int> arrayChange(std::vector<int> &nums, std::vector<std::vector<int>> &operations) {
        std::unordered_map<int, int> um;
        std::unordered_map<int, int> um_reverted;

        for (const auto &operation : operations) {
            if (um_reverted.count(operation[0])) {
                int prev = um_reverted[operation[0]];
                int curr = operation[0];
                int next = operation[1];

                um_reverted.erase(curr);
                um_reverted[next] = prev;
                um[prev] = next;
            } else {
                um[operation[0]] = operation[1];
                um_reverted[operation[1]] = operation[0];
            }
        }

        for (auto &num : nums) {
            if (um.count(num)) {
                num = um[num];
            }
        }

        return nums;
    }
};