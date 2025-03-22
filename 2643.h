#include <vector>

class Solution {
public:
    std::vector<int> rowAndMaximumOnes(std::vector<std::vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int maxIndex = 0;
        int maxCount = 0;

        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                count += mat[i][j];
            }
            if (maxCount < count) {
                maxCount = count;
                maxIndex = i;
            }
        }

        return {maxIndex, maxCount};
    }
};