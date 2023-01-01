#include <vector>

class Solution {
public:
    long long gridGame(std::vector<std::vector<int>> &grid) {
        long long res = LONG_MAX;
        long long sum0 = 0;
        long long sum1 = 0;

        for (const auto &ele : grid[0]) {
            sum0 += ele;
        }

        for (int i = 0; i < grid[0].size(); ++i) {
            sum0 -= grid[0][i];
            res = std::min(res, std::max(sum0, sum1));
            sum1 += grid[1][i];
        }

        return res;
    }
};