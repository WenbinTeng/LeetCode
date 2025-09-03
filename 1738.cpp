#include <queue>
#include <vector>

class Solution {
  public:
    int kthLargestValue(std::vector<std::vector<int>> &matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        std::priority_queue<int, std::vector<int>, std::greater<>> xorQue;
        std::vector<std::vector<int>> xorRec(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                xorRec[i][j] = xorRec[i - 1][j] ^ xorRec[i][j - 1] ^
                               xorRec[i - 1][j - 1] ^ matrix[i - 1][j - 1];

                xorQue.push(xorRec[i][j]);

                if (xorQue.size() <= k)
                    continue;

                xorQue.pop();
            }
        }

        return xorQue.top();
    }
};