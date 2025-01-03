#include <vector>
#include <unordered_map>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int res = 0;
        std::unordered_map<int, int> cnt;

        for (auto num : nums) {
            cnt[num]++;
        }

        for (auto &[_, c] : cnt) {
            if (c == 1)
                return -1;
            else if (c % 3 == 0)
                res += (c / 3);
            else
                res += (c / 3 + 1);
        }

        return res;
    }
};