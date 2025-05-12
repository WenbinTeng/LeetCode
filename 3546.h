#include <vector>

class Solution {
public:
    bool canPartitionGrid(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<long long> verSum(m, 0);
        std::vector<long long> horSum(n, 0);
        std::vector<long long> verPrevSum(m + 1, 0);
        std::vector<long long> horPrevSum(n + 1, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                verSum[i] += grid[i][j];
                horSum[j] += grid[i][j];
            }
        }

        for (int i = 1; i <= m; i++) {
            verPrevSum[i] = verPrevSum[i - 1] + verSum[i - 1];
        }

        for (int i = 1; i <= n; i++) {
            horPrevSum[i] = horPrevSum[i - 1] + horSum[i - 1];
        }

        for (int i = 1; i < m; i++) {
            long long s1 = verPrevSum[i];
            long long s2 = verPrevSum[m] - verPrevSum[i];
            if (s1 == s2)
                return true;
        }

        for (int i = 1; i < n; i++) {
            long long s1 = horPrevSum[i];
            long long s2 = horPrevSum[n] - horPrevSum[i];
            if (s1 == s2)
                return true;
        }

        return false;
    }
};