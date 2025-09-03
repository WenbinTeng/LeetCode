#include <set>
#include <vector>

class Solution {
  public:
    int maxSumSubmatrix(std::vector<std::vector<int>> &matrix, int k) {
        int res = -INT_MAX - 1;
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<int> colSum(n, 0);
        std::set<int> sumSet{0};

        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    colSum[k] += matrix[j][k];
                }

                for (int t = 0, s = 0; t < n; ++t) {
                    s += colSum[t];
                    auto lb = sumSet.lower_bound(s - k);
                    if (lb != sumSet.end()) {
                        res = std::max(res, s - *lb);
                    }
                    sumSet.insert(s);
                }
                sumSet = std::set<int>{0};
            }
            colSum = std::vector<int>(n, 0);
        }

        return res;
    }
};