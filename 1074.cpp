#include <unordered_map>
#include <vector>

class Solution {
  public:
    int numSubmatrixSumTarget(std::vector<std::vector<int>> &matrix,
                              int target) {
        int res = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        std::vector<std::vector<int>> sum(n + 1, std::vector<int>(m + 1));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                            matrix[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                std::unordered_map<int, int> um;

                for (int r = 1; r <= m; r++) {
                    int cur = sum[j][r] - sum[i - 1][r];
                    if (cur == target)
                        res++;
                    if (um.find(cur - target) != um.end())
                        res += um[cur - target];
                    um[cur]++;
                }
            }
        }
        return res;
    }
};