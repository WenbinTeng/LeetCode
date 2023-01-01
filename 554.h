#include <unordered_map>
#include <vector>

class Solution {
public:
    int leastBricks(std::vector<std::vector<int>> &wall) {
        int res = 0;
        int sum = 0;
        std::unordered_map<int, int> um;

        for (int i = 0; i < wall.size(); ++i) {
            for (const auto &w : wall[i]) {
                sum += w;
                ++um[sum];
            }
            um.erase(sum);
            sum = 0;
        }

        for (const auto &[_, cnt] : um) {
            res = std::max(res, cnt);
        }

        return wall.size() - res;
    }
};