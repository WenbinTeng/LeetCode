#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        const int dir[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        std::vector<std::vector<int>> res(m, std::vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int cnt = 0;
                for (int k = 0; k < 9; k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        sum += img[x][y];
                        cnt++;
                    }
                }
                res[i][j] = sum / cnt;
            }
        }

        return res;
    }
};