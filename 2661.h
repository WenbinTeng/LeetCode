#include <vector>
#include <unordered_map>

class Solution {
public:
    int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        std::vector<int> cntRow(m, 0);
        std::vector<int> cntCol(n, 0);
        std::unordered_map<int, std::pair<int, int>> posDict;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                posDict[mat[i][j]] = {i, j};
            }
        }

        for (int index = 0; index < arr.size(); index++) {
            auto [i, j] = posDict[arr[index]];
            cntRow[i]++;
            cntCol[j]++;
            if (cntRow[i] == n)
                return index;
            if (cntCol[j] == m)
                return index;
        }

        return -1;
    }
};