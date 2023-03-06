#include <vector>
#include <unordered_map>

class Solution {
public:
    int sumOfUnique(std::vector<int>& nums) {
        int res = 0;
        std::unordered_map<int, int> cnt;

        for (const auto &num : nums) {
            cnt[num]++;
        }

        for (const auto& [v, c] : cnt) {
            if (c == 1) {
                res += v;
            }
        }

        return res;
    }
};