#include <unordered_map>
#include <vector>

class Solution {
public:
    int longestWPI(std::vector<int> &hours) {
        int res = 0;
        int sum = 0;
        std::unordered_map<int, int> um;

        for (int i = 0; i < hours.size(); i++) {
            sum += hours[i] > 8 ? 1 : -1;
            if (sum > 0) {
                res = std::max(res, i + 1);
            } else if (um.count(sum - 1)) {
                res = std::max(res, i - um[sum - 1]);
            }
            if (!um.count(sum)) {
                um[sum] = i;
            }
        }

        return res;
    }
};