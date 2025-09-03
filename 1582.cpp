#include <vector>

class Solution {
  public:
    int numSpecial(std::vector<std::vector<int>> &mat) {
        int res = 0;
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++) {
            int rowSum = 0;

            for (int j = 0; j < n; j++) {
                rowSum += mat[i][j];
            }

            if (rowSum == 1) {
                int pos = 0;
                while (mat[i][pos] == 0)
                    pos++;
                int colSum = 0;
                for (int k = 0; k < m; k++)
                    colSum += mat[k][pos];
                if (colSum == 1)
                    res++;
            }
        }

        return res;
    }
};