#include <unordered_map>
#include <vector>

class Solution {
public:
    bool isToeplitzMatrix(std::vector<std::vector<int>> &matrix) {
        std::unordered_map<int, int> um;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (um.find(j - i) == um.end()) {
                    um[j - i] = matrix[i][j];
                } else if (um[j - i] != matrix[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
};