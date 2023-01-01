#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> numberOfPairs(std::vector<int> &nums) {
        int pair = 0;
        int rest = 0;
        std::unordered_map<int, int> um;

        for (const auto num : nums) {
            ++um[num];
        }

        for (const auto &[num, cnt] : um) {
            pair += cnt / 2;
            rest += cnt % 2;
        }

        return {pair, rest};
    }
};