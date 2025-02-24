#include <vector>
#include <algorithm>
#include <functional>

class Solution {
public:
    long long maxSum(std::vector<std::vector<int>>& grid, std::vector<int>& limits, int k) {
        int n = grid.size();
        int m = grid[0].size();
        long long res = 0;
        std::vector<int> elect;
        
        for (int i = 0; i < n; i++) {
            std::sort(grid[i].begin(), grid[i].end(), std::greater<int>());
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m && j < limits[i] && grid[i][j] > 0; j++) {
                elect.push_back(grid[i][j]);
            }
        }

        std::sort(elect.begin(), elect.end(), std::greater<int>());

        for (int i = 0; i < k && i < elect.size(); i++) {
            res += elect[i];
        }

        return res;
    }
};